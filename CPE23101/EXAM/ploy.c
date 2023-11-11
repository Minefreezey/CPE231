#include <stdio.h>
#include<string.h>
void selectionsort(char arr[]){
    int i,j,min;
    char temp;
    for (i=0;i<strlen(arr)-1;i++){
        min=i;
        for (j=i+1;j<strlen(arr);j++){
            if (arr[j]<arr[min]){
                min=j;
            }
        }
        //swap
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
void bubblesort(char arr[]){
    int i,j;
    char temp;
    for (i=1;i<strlen(arr)-1;i++){
        for(j=0;j<strlen(arr)-i;j++){
            if (arr[j+1]<arr[j]){
                //swap
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void Insertionsort(char arr[]){
    int i,j;
    char temp;
    for(i=1;i<strlen(arr);i++){
        temp=arr[i];
        j=i-1;
        while (j>=1 && arr[i]>temp)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
        
    }
}
void printarray (char arr[]){
    int i;
    for (i=0;i<strlen(arr);i++){
        printf("%c ",arr[i]);
    }
}
int main(){
    char arr[10]="MONGKUT";
    selectionsort(arr);
    printarray(arr);
    printf("\n");
    char arr2[10]="MONGKUT";
    bubblesort(arr2);
    printarray(arr2);
    printf("\n");
    char arr3[10]="MONGKUT";
    Insertionsort(arr3);
    printarray(arr3);
}