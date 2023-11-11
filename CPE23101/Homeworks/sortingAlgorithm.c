#include <stdio.h>
#include <string.h>

void merge(char* text, int left, int right, int mid){
    int sizeLeft = (mid - left) + 1;
    int sizeRight = (right - (mid+1)) + 1;
    int newArr[(right-left)+1];
    int i=0,j=0,k=0;
    while (i < sizeLeft && j < sizeRight){
        if (text[left+i] < text[(mid+1)+j]){
            newArr[k] = text[left+i];
            i++;
        }
        else{
            newArr[k] = text[(mid+1)+j];
            j++;
        }
        k++;
    }
    if (i == sizeLeft){
        while (j<sizeRight){
            newArr[k] = text[(mid+1)+j];
            j++;
            k++;
        }
    }
    else{
        while (i<sizeLeft){
            newArr[k] = text[left+i];
            i++;
            k++;
        }
    }
    for (i =0;i<(right-left)+1;i++){
        text[left+i] = newArr[i];
    }
}

void mergeSort(char* text, int l, int r){
    if ((r-l) > 0){
        int mid = ((l+r)/2);
        mergeSort(text, l, mid);
        mergeSort(text, mid+1, r);
        merge(text,l,r,mid);
    }
}

int main(){
    char text[1000];
    printf("Input text to sort (CAPITAL LETTER ONLY) > ");
    scanf("%s",text);
    mergeSort(text,0,strlen(text)-1);  
    printf("SORTED CHARACTER : %s",text);
    return 0;
}