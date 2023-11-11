#include<stdio.h>

void printarr(int* arr, int n){
    for (int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
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
    int arr1[] = {46,52,3,1,5,7,45,12,654,87,452,187,286};
    int n1 = (int) sizeof(arr1) / (int) sizeof(int);
    printf("Merge sorted : ");
    mergeSort(arr1,0,n1-1);
    printarr(arr1, n1);

    printf("\n");

    // int arr2[] = {17,28,3,6,12,9,17,12};
    // int arr2[] = {1,2,3,4,5,6,7,8,9,10};
    // int arr2[] = {10,9,8,7,6,5,4,3,2,1};
    // int arr2[] = {1,2,4,8,4,51,321,4,2,8,1,3,5,54,2654,5,231};
    int n2 = (int) sizeof(arr2) / (int) sizeof(int);
    printf("Quick sorted : ");
    quickSort(arr2,0,n2-1);
    printarr(arr2, n2);

}