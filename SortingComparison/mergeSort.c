#include<stdio.h>
#include<time.h>

void printarr(int* arr, int n){
    for (int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void merge(int* arr, int l, int r, int mid){
    int sizeLeft = (mid - l) + 1;
    int sizeRight = (r - (mid+1)) +1;
    int newArr[(r-l) + 1];
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
    mergeSort(arr,0,n-1);
    clock_t end = clock();
    printarr(arr,n);
    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken: %f\n",time_taken);
    return 0;
}