#include <stdio.h>

void printarr(int* arr, int n){
    for (int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void selectionSort(int* arr, int n){
    int i;
    for (i=0;i<n-1;i++){
        int minn = i;
        for (int j=i+1;j<n;j++){
            if (arr[j] < arr[minn]){
                minn = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minn];
        arr[minn] = temp;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for (i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,n);
    printarr(arr,n);
    return 0;
}
