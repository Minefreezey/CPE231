/*
 * CPE231 : ALGORITHMS
 * Module 1 Examination
 * ----------------------------------------------------------
 * Bubble, Insertion, Selection sort
 * 65070501050 | WONGSATORN SUNGSILPAWECH
 * Section B, Regular CPE
 * ----------------------------------------------------------
 * Date : 11th, September 2023
 * Semester 1 Academic year 2023
*/

#include <stdio.h>

void printarr(int* arr, int n){
    for (int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubbleSort(int* arr, int n){
    for (int i = 0;i<n;i++){
        for (int j = 0; j<n-i;j++){
            if (arr[j] >= arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int* arr, int n){
    for (int i = 1;i<n;i++){
        int what = arr[i];
        int j;
        for (j = i-1; j>=0 && arr[j] > what;j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = what;
    }
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
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int n = (int)sizeof(arr) / (int)sizeof(int);
    bubbleSort(arr, n);
    printf("BUBBLE SORTED : ");
    printarr(arr,n);
    printf("\n");



    int arr2[] = {9,8,7,6,5,4,3,2,1};
    int n2 = (int)sizeof(arr2) / (int)sizeof(int);
    insertionSort(arr2, n2);
    printf("INSERTION SORTED : ");
    printarr(arr2,n2);
    printf("\n");


    int arr3[] = {9,8,7,6,5,4,3,2,1};
    int n3 = (int)sizeof(arr3) / (int)sizeof(int);
    selectionSort(arr3, n3);
    printf("SELECTION SORTED : ");
    printarr(arr3,n3);
    printf("\n");


    return 0;
}
