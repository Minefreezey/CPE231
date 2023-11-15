#include<stdio.h>
#include <time.h>

void printarr(int* arr, int n){
    for (int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");   
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int left, int right){
    int pivot = arr[left];
    int i = left;
    int j = right+1;
    while (i< j){
        do{
            i++;
        }while (i < right && arr[i] <= pivot);
        do{
            j--;
        }while (j >= left && arr[j] > pivot); // it must be while (arr[j] > pivot) 
        if (i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[left],&arr[j]);
    return j;

}

void quickSort(int* arr, int l, int r){
    if (l < r){
        int indexPivot = partition(arr,l,r);
        quickSort(arr,l,indexPivot-1);
        quickSort(arr,indexPivot+1,r);
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
    quickSort(arr,0, n-1);
    clock_t end = clock();
    printarr(arr,n);
    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken: %f\n",time_taken);
    return 0;
}