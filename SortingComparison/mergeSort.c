#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void printarr(int* arr, int n){
    for (int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void merge(int* arr, int l, int r, int mid){
    int sizeLeft = (mid - l) + 1;
    int sizeRight = (r - (mid+1)) +1;
    int* newArr = malloc(sizeof(int)*(r-l+1));
    int i =0;
    int j=0;
    int k=0;
    while(i < sizeLeft && j < sizeRight){
        if (arr[l+i] < arr[(mid+1)+j]){
            newArr[k] = arr[l+i];
            i++;
            k++;
        }
        else{
            newArr[k] = arr[(mid+1)+j];
            j++;
            k++;
        }
    }

    if (i == sizeLeft){
        while (j < sizeRight){
            newArr[k] = arr[(mid+1)+j];
            j++;
            k++;
        }
    }
    else{
        while (i < sizeLeft){
            newArr[k] = arr[l+i];
            i++;
            k++;
        }
    }

    for (i =0;i<(r-l)+1;i++){
        arr[l+i] = newArr[i];
    }
}

void mergeSort(int* arr, int l, int r){
    if (r > l){
        int mid = ((l+r)/2);
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,r,mid);
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
    mergeSort(arr,0, n-1);
    clock_t end = clock();
    printarr(arr,n);
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n", time_taken);
    free(arr);
    return 0;
}