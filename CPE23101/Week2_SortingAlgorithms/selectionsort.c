#include <stdio.h>
#include <string.h>
int SelecTionSort(char InPutArray[]){
    int i,j,min;
    char temp;
    for (i =0;i<strlen(InPutArray)-1;i++){
        min=i;
        for (j=i+1; j<strlen(InPutArray);j++){
            if (InPutArray[j]<InPutArray[min]){
                min=j;
            }
        }
        //swap
        temp=InPutArray[i];
        InPutArray[i]=InPutArray[min];
        InPutArray[min]=temp;
    }
}
int printArray(char InPutArray[]){
    int i;
    for (i=0;i<strlen(InPutArray);i++){
        printf("%c",InPutArray[i]);
    }

}
int main(){
    char InPutArray[10]="MONGKUT";
    SelecTionSort(InPutArray);
    printArray(InPutArray);
    return 0;
}