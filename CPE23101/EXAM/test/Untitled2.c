#include <stdio.h>

void printarr(int* arr, int n){
    for (int i =0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int* arr, int left, int right, int mid){
    int sizeLeft = (mid - left ) + 1;
    int sizeRight = (right - (mid+1)) + 1;
    int newArr[(right-left)+1];

    int i=0;
    int j=0;
    int k=0;

    while (i < sizeLeft && j < sizeRight){
        if (arr[left+i] < arr[(mid+1)+j]){
            newArr[k] = arr[left+i];
            i++;
            k++;
        }
        else {
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
            newArr[k] = arr[left+i];
            i++;
            k++;
        }
    }

    for (int x = 0;x<(right-left)+1;x++){
        arr[left+x] = newArr[x];
    }
}

void mergeSort(int* arr, int l, int r){
    if (l < r){
        int mid = (l+r) / 2;
        mergeSort(arr,l,mid);
        mergeSort(arr, mid+1, r);
        merge(arr,l,r,mid);
    }
}

void swap(int* a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int left, int right){
    int pivot = arr[left];
    int i = left;
    int j = right+1;

    while (i<j){
        do{
            i++;
        }while (arr[i] <= pivot);
        do{
            j--;
        }while (arr[j] > pivot);
        if (i < j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[left], &arr[j]);
    return j;
}

void quickSort(int* arr, int l,int r){
    if (l< r){
        int indexPivot = partition(arr, l ,r);
        quickSort(arr, l, indexPivot-1);
        quickSort(arr,indexPivot+1, r);
    }

}

int main(){
    printf("Merge Sorted : ");
    int arr1[] = {9,8,7,6,6,4,5,4,3,2,1};
    int n1 = (int) sizeof(arr1) / (int) sizeof(int);
    mergeSort(arr1, 0, n1-1);
    printarr(arr1,n1);


    printf("Quick sorted : ");
    int arr2[] = {9,8,7,54,8565,1324,86754,321,546};
    int n2 = (int) sizeof(arr2) / (int) sizeof(int);
    quickSort(arr2, 0, n2-1);
    printarr(arr2,n2);
    return 0;
}
