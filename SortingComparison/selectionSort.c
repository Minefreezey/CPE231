#include <stdio.h>
#include <time.h>

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
    selectionSort(arr,n);
    clock_t end = clock();
    printarr(arr,n);
    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken: %f\n",time_taken);
    return 0;
}
