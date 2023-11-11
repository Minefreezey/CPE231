#include<stdio.h>
#include<string.h>
int levenshtienEdit(char* first, char* second, int len1, int len2){
    int matrix[len1+1][len2+1];
    for (int i =0;i<=len1;i++){
        matrix[i][0] = i;
    }
    for (int i = 0;i<=len2;i++){
        matrix[0][i] = i;
    }
    

    for (int i =1;i<=len1;i++){
        for (int j =1;j<=len2;j++){
            int minToAdd = 2147483647;
            int substitution = 0;
            if (first[i-1] != second[j-1]){
                substitution = 1;
            }
            if (matrix[i-1][j] + 1 < minToAdd){
                minToAdd = matrix[i-1][j] +1 ;
            }
            if (matrix[i][j-1] + 1 < minToAdd){
                minToAdd = matrix[i][j-1] +1;
            }
            if (matrix[i-1][j-1] + substitution < minToAdd){
                minToAdd = matrix[i-1][j-1] + substitution;
            }
            matrix[i][j] = minToAdd;
        }
    }

    // for (int i =0;i<len1+1;i++){
    //     for (int j=0;j<len2+1;j++){
    //         printf("%d\t",matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    return matrix[len1][len2];

}

int main(){
    char firstText[105];
    char secondText[105];
    fgets(firstText,101,stdin);
    fgets(secondText,101,stdin);
    int len1 = strlen(firstText);
    int len2 = strlen(secondText);
    firstText[len1-1] = '\0';
    secondText[len2-1] = '\0';
    len1 = strlen(firstText);
    len2 = strlen(secondText);
    // printf("%s (%d)\n",firstText, strlen(firstText));
    // printf("%s (%d)\n",secondText, strlen(secondText));
    int ans = levenshtienEdit(firstText, secondText, len1, len2);
    printf("%d",ans);
}