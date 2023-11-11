#include<stdio.h>

int searchList(int* list, int what, int left, int right){
    int mid;
    while (left <= right){
        mid = (left+right)/2;
        if (list[mid] > what){
            right = mid -1;
        }
        else if (list[mid] < what){
            left = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int list[n+5];
    int search[k+5];
    for (int i =0;i<n;i++){
        scanf("%d",&list[i]);
    }

    for (int i =0;i<k;i++){
        scanf("%d",&search[i]);
    }

    for (int i =0;i<k;i++){
        int ans = searchList(list,search[i],0,n-1);
        printf("%d\n",ans);
    }
    return 0;
}