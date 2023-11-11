#include <stdio.h>

void printarr(int* arr, int n){
    for (int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void bubbleSort(int* arr, int n){
    for (int i =0;i<n;i++){
        for (int j=0;j<n-i;j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int* arr, int n){
    for (int i =0;i<n;i++){
        int min = i;
        for (int j= i+1;j<n;j++){
            if (arr[j] < arr[min]){
                min  = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int* arr, int n){
    for (int i =1;i<n;i++){
        int what = arr[i];
        int j;
        for (j= i-1; j>=0 && arr[j] > what ;j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = what;
    }

}

int main(){
    printf("Bubble sorted : ");
    int arr1[] = {9,9,8,7,6,5,4,3,2,1};
    int n1 = (int) sizeof(arr1) / (int) sizeof(int);
    bubbleSort(arr1,n1);
    printarr(arr1,n1);
    printf("\n");

    printf("Selection sorted : ");
    int arr2[] = {9,8,7,6,5,5,4,3,2,1};
    int n2 = (int) sizeof(arr2) / (int) sizeof(int);
    selectionSort(arr2,n2);
    printarr(arr2,n2);
    printf("\n");

    printf("Insertion sorted : ");
    int arr3[] = {9,8,7,6,6,5,4,3,2,1};
    int n3 = (int) sizeof(arr3) / (int) sizeof(int);
    insertionSort(arr3,n3);
    printarr(arr3,n3);
    printf("\n");
    return 0;
}
