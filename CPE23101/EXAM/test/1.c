/*
65070501050 | WONGSATORN SUNGSILPAWECH
*/

#include<stdio.h>

void printarr(int* arr, int n){
    for (int i =0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int* arr, int n){
    for (int i =0;i<n-1;i++){
        for (int j = 0;j<n-1;j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int* arr, int n){
    for (int i =0; i<n;i++){
        int min = i;
        for (int j=i+1;j<n;j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void insertionSort(int* arr, int n){
    for (int i = 1;i<n;i++){
        int what = arr[i];
        int j;
        for (j = i-1; j>= 0 && arr[j] > what ;j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = what;
    }
}

int main(){
    printf("Bubble Sorted : ");
    int arr1[] = {42,51,84,984,561,21,56,261,574,152,542,124};
    int n1 = (int) sizeof(arr1) / (int) sizeof(int);
    bubbleSort(arr1, n1);
    printarr(arr1,n1);

    printf("Selection Sorted : ");
    int arr2[] = {9,8,7,6,5,4,3,2,1,0};
    int n2 = (int) sizeof(arr2) / (int) sizeof(int);
    selectionSort(arr2,n2);
    printarr(arr2,n2);

    printf("Insertion Sorted : ");
    int arr3[] = {9,8,7,6,554,615,21,20,21,354,4,3,2,1,0};
    int n3 = (int) sizeof(arr3) / (int) sizeof(int);
    insertionSort(arr3,n3);
    printarr(arr3,n3);

    return 0;
}
