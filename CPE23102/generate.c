#include<stdio.h>

void permutation(int,a,int i, int n){
    if (i == n){
        printf("%d ",i);
        return;
    }
    printf("%d ",i);
    permutation(a,i+1,n);
}

int main(){
    printf("Input number for permutation > ");
    int n;
    scanf("%d",&n);

    permutation(1,1,n);
}