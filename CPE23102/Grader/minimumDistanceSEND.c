#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>

typedef struct point{
    double x;
    double y;
}POINT;

double dist(POINT p1, POINT p2){
    return sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2));
}

int compareX(const void* a, const void* b){
    POINT* pa = (POINT*) a;
    POINT* pb = (POINT*) b;

    if (pa->x < pb->x){
        return -1;
    }
    else if (pa -> x > pb -> x){
        return 1;
    }
    return 0;
}

int compareY(const void* a, const void* b){
    POINT* pa = (POINT*) a;
    POINT* pb = (POINT*) b;

    if (pa->y < pb->y){
        return -1;
    }
    else if (pa -> y > pb -> y){
        return 1;
    }
    return 0;
}

double bruteForce(POINT* coX, int n){
    double mindis = DBL_MAX;
    for (int i =0;i<n;i++){
        for (int j=i+1;j<n;j++){
            double dis = dist(coX[i], coX[j]);
            if (dis < mindis){
                mindis = dis;
            }
        }
    }
    return mindis;
}

void genY(POINT* newY, POINT* coX, int n){
    for (int i =0;i<n;i++){
        newY[i].x = coX[i].x;
        newY[i].y = coX[i].y;
    }
    qsort(newY, n, sizeof(POINT), compareY);
}

int genPointstrip(POINT* strip, POINT* coY, double median, double delta, int n){
    int numPointStrip = 0;
    for (int i =0;i<n;i++){
        if (fabs(coY[i].x - median) <= delta){
            strip[numPointStrip].x = coY[i].x;
            strip[numPointStrip].y = coY[i].y;
            numPointStrip++;
        }      
    }
    return numPointStrip;
}

double closestPair(POINT* coX, POINT* coY, int n){
    // printf("=====LIST of the point passed=====\n");
    // printf("coX :\n");
    // for (int i =0; i<n;i++){
    //     printf("%.2lf, %.2lf\n",coX[i].x, coX[i].y);
    // }
    // printf("coY :\n");
    // for (int i =0; i<n;i++){
    //     printf("%.2lf, %.2lf\n",coY[i].x, coY[i].y);
    // }
    if (n <= 3){
        return bruteForce(coX,n);
    }
    int nLeft = ceil(n*0.5);
    // printf("Copy first %d to the LEFT\n",nLeft);
    int nRight = n - nLeft;
    POINT newYL[nLeft];
    POINT newYR[nRight];
    genY(newYL, coX, nLeft);
    genY(newYR, coX+nLeft, nRight);
    double deltaL = closestPair(coX, newYL, nLeft);
    double deltaR = closestPair(coX+nLeft, newYR, nRight);
    // printf("DeltaL : %.4lf | DeltaR : %.4lf\n",deltaL,deltaR);
    double delta;
    if (deltaL < deltaR){
        delta = deltaL;
    }
    else{
        delta = deltaR;
    }
    double medianX = coX[nLeft-1].x;
    double medianY = coX[nLeft-1].y;
    // printf("The median of X coordinate is %.2lf, %.2lf\n",medianX,medianY);
    POINT strip[n];
    int numStrip = genPointstrip(strip, coY, medianX, delta, n);
    // printf("The number of Strip on the left where medianX is %.2lf [%.2lf - %.2lf] ARE %d:\n",medianX,medianX-delta,medianX+delta,numStrip);
    // for (int i =0;i<numStrip;i++){
    //     printf("%.2lf %.2lf\n",strip[i].x, strip[i].y);
    // }
    for (int i =0;i<numStrip;i++){
        for (int j=i+1; j < numStrip && fabs(strip[i].y - strip[j].y) <= delta ; j++){
            if (dist(strip[i], strip[j]) <= delta){
                delta = dist(strip[i], strip[j]);
            }
        }
    }
    return delta;
}

int main(){
    int nPoint;
    scanf("%d",&nPoint);
    POINT coordinateX[nPoint];
    POINT coordinateY[nPoint];
    for (int i =0;i<nPoint;i++){
        scanf("%lf %lf", &coordinateX[i].x, &coordinateX[i].y);
        coordinateY[i].x = coordinateX[i].x;
        coordinateY[i].y = coordinateX[i].y;
    }
    qsort(coordinateX, nPoint, sizeof(POINT),compareX);
    qsort(coordinateY, nPoint, sizeof(POINT),compareY);
    // printf("SORTED X=========\n");
    // for (int i =0;i<nPoint;i++){
    //     printf("%.2lf %.2lf\n", coordinateX[i].x, coordinateX[i].y);
    // }
    // printf("SORTED Y=========\n");
    // for (int i =0;i<nPoint;i++){
    //     printf("%.2lf %.2lf\n", coordinateY[i].x, coordinateY[i].y);
    // }
    double ans = closestPair(coordinateX, coordinateY, nPoint);
    printf("%.4lf\n",ans);
    return 0;
}