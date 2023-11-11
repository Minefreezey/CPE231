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

int genPointstrip(POINT* strip, POINT* coY, double median, double delta, int n, char mode){
    int numPointStrip = 0;
    for (int i =0;i<n;i++){
        if (mode == 'L'){
            if (coY[i].x <= median && coY[i].x > (median-delta)){
                strip[numPointStrip].x = coY[i].x;
                strip[numPointStrip].y = coY[i].y;
                numPointStrip++;
            }            
        }
        else if (mode == 'R'){
            if (coY[i].x > median && coY[i].x < (median+delta)){
                strip[numPointStrip].x = coY[i].x;
                strip[numPointStrip].y = coY[i].y;
                numPointStrip++;
            }            
        }        
    }
    return numPointStrip;
}

int genStrip(POINT* strip, POINT* coY, double median, double delta, int n){
    int numStrip =0;
    for (int i=0;i<n;i++){
        if ((coY[i].x <= median && coY[i].x >= (median-delta)) || (coY[i].x > median && coY[i].x <= (median+delta)))
        strip[numStrip].x = coY[i].x;
        strip[numStrip].y = coY[i].y;
        numStrip++;
    }
}

double closestPair(POINT* coX, POINT* coY, int n){
    printf("=====LIST of the point passed=====\n");
    for (int i =0; i<n;i++){
        printf("%.2lf, %.2lf\n",coX[i].x, coX[i].y);
    }
    if (n <= 3){
        return bruteForce(coX,n);
    }
    int nLeft = ceil(n*0.5);
    printf("Copy first %d to the LEFT\n",nLeft);
    int nRight = n - nLeft;
    double deltaL = closestPair(coX, coY, nLeft);
    double deltaR = closestPair(coX+nLeft, coY+nLeft, nRight);
    printf("DeltaL : %.4lf | DeltaR : %.4lf\n",deltaL,deltaR);
    double delta;
    if (deltaL < deltaR){
        delta = deltaL;
    }
    else{
        delta = deltaR;
    }
    double medianX = coX[nLeft-1].x;
    double medianY = coX[nLeft-1].y;
    printf("The median of X coordinate is %.2lf, %.2lf\n",medianX,medianY);
    POINT stripLeft[n];
    POINT stripRight[n];
    int numStripLeft = genPointstrip(stripLeft, coY, medianX, delta, n, 'L');
    printf("The number of Strip on the left where medianX is %.2lf [%.2lf - %.2lf] ARE %d:\n",medianX,medianX,medianX-delta,numStripLeft);
    for (int i =0;i<numStripLeft;i++){
        printf("%.2lf %.2lf\n",stripLeft[i].x, stripLeft[i].y);
    }
    int numStripRight = genPointstrip(stripRight, coY, medianX, delta, n, 'R');
    printf("The number of Strip on the right where medianX is %.2lf [%.2lf - %.2lf] ARE %d:\n",medianX,medianX,medianX+delta,numStripRight);
    for (int i =0;i<numStripRight;i++){
        printf("%.2lf %.2lf\n",stripRight[i].x, stripRight[i].y);
    }
    for (int i =0;i<numStripLeft;i++){
        for (int j = 0;j<numStripRight;j++){
            if (fabs(stripLeft[i].y - stripRight[j].y) < delta){
                if (dist(stripLeft[i], stripRight[j]) < delta){
                    delta = dist(stripLeft[i], stripRight[j]);
                }
            }
        }
    }
    return delta;
}

int main(){
    int nPoint;
    scanf("%d",&nPoint);
    POINT coordinateX[nPoint+5];
    POINT coordinateY[nPoint+5];
    for (int i =0;i<nPoint;i++){
        scanf("%lf %lf", &coordinateX[i].x, &coordinateX[i].y);
        coordinateY[i].x = coordinateX[i].x;
        coordinateY[i].y = coordinateX[i].y;
    }
    qsort(coordinateX, nPoint, sizeof(POINT),compareX);
    qsort(coordinateY, nPoint, sizeof(POINT),compareY);
    printf("SORTED X=========\n");
    for (int i =0;i<nPoint;i++){
        printf("%.2lf %.2lf\n", coordinateX[i].x, coordinateX[i].y);
    }
    printf("SORTED Y=========\n");
    for (int i =0;i<nPoint;i++){
        printf("%.2lf %.2lf\n", coordinateY[i].x, coordinateY[i].y);
    }
    double ans = closestPair(coordinateX, coordinateY, nPoint);
    printf("====\nTHE ANS is %.4lf\n",ans);
    return 0;
}