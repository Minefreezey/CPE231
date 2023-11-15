#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printarr(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int left, int right){
    int pivot = arr[left];
    int i = left;
    int j = right + 1;
    while (i < j)
    {
        do
        {
            i++;
        } while (i < right && arr[i] <= pivot);
        do
        {
            j--;
        } while (j >= left && arr[j] > pivot); // it must be while (arr[j] > pivot)
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[left], &arr[j]);
    return j;
}

void quickSort(int arr[], int left, int right) {
    while (left < right) {
        int pivotIndex = partition(arr, left, right);
        if (pivotIndex - left < right - pivotIndex) {
            quickSort(arr, left, pivotIndex - 1);
            left = pivotIndex + 1;
        } else {
            quickSort(arr, pivotIndex + 1, right);
            right = pivotIndex - 1;
        }
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
    quickSort(arr,0, n-1);
    clock_t end = clock();
    printarr(arr,n);
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n", time_taken);
    free(arr);
    return 0;
}