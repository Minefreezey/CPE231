#include <stdio.h>

void printarr(int* arr, int n){
    for (int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void insertionSort(int* arr, int n){
    for (int i = 1;i<n;i++){
        int what = arr[i];
        int j;
        for (j = i-1; j>=0 && arr[j] > what;j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = what;
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
    insertionSort(arr,n);
    printarr(arr,n);
    return 0;
}
