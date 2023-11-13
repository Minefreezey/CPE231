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

int main(){
    FILE* file1000 = fopen("1000_random_unique_2.txt","r");
    if (file1000 == NULL){
        return -1;
    }
    int n;
    fscanf(file1000,"%d",&n);
    int arr[n];
    int i;
    for (i = 0;i<n;i++){
        fscanf(file1000, "%d", &arr[i]);
    }
    fclose(file1000);
    bubbleSort(arr,n);
    printarr(arr,n);
    return 0;
}