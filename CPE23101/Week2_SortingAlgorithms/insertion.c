#include<stdio.h>
#include<stdlib.h>


int counting(int *arr){
    int i=0,count=0;
    while(arr[i] != NULL){
        count++;
        i++;
    }
    return count;
}
void insertionSort(int *arr){
    int count = counting(arr);
    int temp,i,j;
    for(i=1;i<=count-1;i++){
        temp = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    for(int k=0 ; k<count;k++){
        printf("%d ",arr[k]);
    }
    printf("\n");
}
int main(){
    int arr[32] = {99,17,55,66,89,78,111,189,156};
    insertionSort(arr);
    return 0;
}
