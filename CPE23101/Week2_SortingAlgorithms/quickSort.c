#include <stdio.h>

int partition(int *arr, int left, int right){
    int pivot = *(arr);
    int i = left;
    int j = right;
    while (i <= j){
        while (arr[i] < pivot && i<=right){
            i++;
        }
        while (arr[j] > pivot && j >= left){
            j--;
        }
    }
    printf("%d",pivot);
    return 0;

}

int quickSort(int *arr, int l,int r){
    int pivotLocation = partition(arr,l,r);
    return 0;
}

int main(){
    int n;
    printf("Enter n > ");
    scanf("%d", &n);

    int arr[n+5];

    for (int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    quickSort(arr,0,(n-1));

    return 0;
}