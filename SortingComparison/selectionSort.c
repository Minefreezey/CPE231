#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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

int main(int argc, char *argv[]){
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Can't open this File : %s\n", argv[1]);
        return -1;
    }
    int n;
    fscanf(fp, "%d", &n);
    unsigned int *arr = malloc(sizeof(int) * n);
    int j;
    for (j = 0; j < n; j++)
    {
        fscanf(fp, "%u", &arr[j]);
    }
    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();
    printarr(arr,n);
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n", time_taken);
    free(arr);
    return 0;
}
