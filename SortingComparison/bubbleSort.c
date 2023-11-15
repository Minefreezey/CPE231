#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printarr(unsigned int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%u ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(unsigned int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]){
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Can't open this File : %s\n", argv[1]);
        return -1;
    }
    int n;
    fscanf(fp, "%d", &n);
    unsigned int *arr = malloc(sizeof(int) * n);
    int j;
    for (j = 0; j < n; j++)
    {
        fscanf(fp, "%u", &arr[j]);
    }
    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();
    printarr(arr,n);
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n", time_taken);
    free(arr);
    return 0;
}
