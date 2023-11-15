#include <stdio.h>
#include <time.h>

void printarr(int* arr, int n){
    for (int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubbleSort(int* arr, int n){
    for (int i = 0;i<n;i++){
        for (int j = 0; j<n-i;j++){
            if (arr[j] >= arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    FILE* fp = fopen("testCases/random_unique_10000.txt","r");
    if (fp == NULL){
        return -1;
    }
    fscanf(fp,"%d",&n);
    int arr[n];
    int i;
    for (i = 0;i<n;i++){
        fscanf(fp, "%d", &arr[i]);
    }
    clock_t start = clock();
    bubbleSort(arr,n);
    clock_t end = clock();
    printarr(arr,n);
    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken: %f\n",time_taken);
    return 0;
}