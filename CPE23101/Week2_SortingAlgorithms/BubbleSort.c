#include <stdio.h>
#include <string.h>

char *bubbleSort(char Input[], int lenght) {
    char temp;
    for(int i=0;i<lenght-1;i++) {
        for(int j=0;j<lenght-1;j++) {
            if(Input[j] > Input[j+1]) {
                temp = Input[j];
                Input[j] = Input[j+1];
                Input[j+1] = temp;
            }
        }
    }
    return Input;
}

int main() {
    char Input[] = "MONGKUT";
    printf("Input : %s\n",Input);
    char Output[10];
    strcpy(Output,bubbleSort(Input, strlen(Input)));
    printf("Output : %s\n",Output);
    return 0;
}