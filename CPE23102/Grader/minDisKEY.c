#include<stdio.h>
#include <math.h>
int main(){
    int n;
    scanf("%d",&n);
    double x[n+12];
    double y[n+12];
    double x1,x2,y1,y2;
    double mindis = 2147483647.00;
    for (int i =0;i<n;i++){
        scanf("%lf %lf", &x[i], &y[i]);
    }

    for (int i =0;i<n;i++){
        for (int j = i+1 ; j<n ;j++){
            double dis = sqrt(pow(x[i]-x[j],2) + pow(y[i]-y[j],2));
            // printf("dis is %.17lf\n",dis);
            if (dis < mindis){
                mindis = dis;
                x1 = x[i];
                x2 = x[j];
                y1 = y[i];
                y2 = y[j];
                // printf("FOUND NEW mindis = %.4lf\n", mindis);
                // printf("POINT 1 : %.2lf, %.2lf\n", x1,y1);
                // printf("POINT 2 : %.2lf, %.2lf\n", x2,y2);
            }
        }
    }

    printf("%.4lf\n", mindis);
    printf("POINT 1 : %.2lf, %.2lf\n", x1,y1);
    printf("POINT 2 : %.2lf, %.2lf\n", x2,y2);
}