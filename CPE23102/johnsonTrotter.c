#include<stdio.h>
#include<string.h>
#include<time.h>

void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void initialDirection(char* text, char* direction, int len){
    for (int i =0;i < len;i++){
        direction[i] = 'L'; // LEFT ARROW
    }
}

int checkMobile(char* text, char* direction, int len){
    for (int i =0;i<len;i++){
        if (direction[i] == 'L'){
            if (i > 0 && text[i] > text[i-1]){
                return 1;
            }
        }
        else if (direction[i] == 'R'){
            if (i<len-1 && text[i] > text[i+1]){
                return 1;
            }
        }
    }
    return 0;
}

int findMaxMobile(char* text, char* direction, int len){
    int indexMax;
    char maxMobile = 0;
    for (int i =0;i<len;i++){
        if (direction[i] == 'L'){
            if (i > 0 && text[i] > text[i-1] && text[i] > maxMobile){
                maxMobile = text[i];
                indexMax = i;
            }
        }
        else if (direction[i] == 'R'){
            if (i<len-1 && text[i] > text[i+1] && text[i] > maxMobile){
                maxMobile = text[i];
                indexMax = i;
            }
        }
    }
    return indexMax;
}

void reverseArrow(char* text, char* direction, int indexMaxMobile, int len){
    for (int i=0;i<len;i++){
        if (text[i] > text[indexMaxMobile]){
            if (direction[i] == 'L'){
                direction[i] = 'R';
            }
            else if (direction[i] == 'R'){
                direction[i] = 'L';
            }
        }
    }
}

void swapByArrow(char* text, int* where, char* direction){
    if (direction[*where] == 'L'){
        swap(&text[*where],&text[*where-1]);
        swap(&direction[*where],&direction[*where-1]);
        *where = (*where)-1;
    }
    else if (direction[*where] == 'R'){
        swap(&text[*where], &text[*where+1]);
        swap(&direction[*where],&direction[*where+1]);
        *where = (*where)+1;
    }
}

void printarr(char* text, int len){
    for (int i =0;i<len;i++){
        printf("%c ", text[i]);
    }
    printf("\n");
}

void johnsonTrotter(char* text, char* direction, int len){
    
    initialDirection(text, direction, len);
    int mobileFlag = checkMobile(text, direction, len);
    printarr(text, len);
    while (mobileFlag != 0){
        int indexMaxMobile = findMaxMobile(text,direction,len);
        swapByArrow(text, &indexMaxMobile, direction);
        reverseArrow(text, direction, indexMaxMobile, len);
        mobileFlag = checkMobile(text, direction, len);
        printarr(text, len);
    }
}

void bruteForcePermutation(char* text, int l, int r, int len){
    if (l == r){
        printarr(text, len);
    }
    else{
        for (int i = l; i <= r; i++){
            swap(&text[l],&text[i]);
            bruteForcePermutation(text,l+1,r,len);
            swap(&text[l],&text[i]);
        }
    }
}

int main(){
    clock_t startJ, endJ, startB, endB;
    char text[101];
    char text2[101];
    char direction[101];
    printf("Enter a string sequence to create permutation (MAX of 100 Characters, CAPITAL letters only) > ");
    fgets(text,100,stdin);
    int len = strlen(text);
    text[len-1] = '\0';
    len = strlen(text);
    strcpy(text2,text);

    startJ = clock();
    printf("================Using Johnson Trotter Algorithm====================\n");
    johnsonTrotter(text,direction,len);
    endJ = clock();
    double time_john = (double)(endJ-startJ) / (double)(CLOCKS_PER_SEC);
    printf("Time taken = %.10lf\n",time_john);
    printf("==================================================================\n\n");

    int len2 = strlen(text2);
    startB = clock();
    printf("=================Using Brute Force (Recursive)====================\n");
    bruteForcePermutation(text2,0,len2-1, len2);
    endB = clock();
    double time_brute = (double)(endB-startB) / (double)(CLOCKS_PER_SEC);
    printf("Time taken = %.10lf\n",time_brute);
    printf("==================================================================\n");
    return 0;
}