#include<stdio.h>
#include<string.h>

void printArr(int* arr, int size){
    for (int i =0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void initialarr(int* arr, int size){
    for (int i =0;i<size;i++){
        arr[i] = 50002;
    }
}

int minChangetoCoin(int money, int nCoin, int* coin){
    int dp[money+1];
    char coinUsed[money+1][money+1];
    strcpy(coinUsed[0], "0");
    initialarr(dp, money+1);
    dp[0] = 0;
    
    for (int i =1;i<=money;i++){
        for (int j = 0; j<nCoin;j++){
            if (i >= coin[j]){
                printf("dp[%d - coin[%d] (%d)] + 1 = %d\n",i,j,coin[j],dp[i - coin[j]] + 1 );

                printf("Check that %d < %d ?\n",dp[i - coin[j]] + 1,dp[i]);
                if (dp[i - coin[j]] + 1 < dp[i]){
                    dp[i] = dp[i-coin[j]] + 1;
                    char cat = coin[j] + 48;
                    strcpy(coinUsed[i], strcat(coinUsed[i-coin[j]], &cat));
                    printf("NOW coin used is %s\n",coinUsed[i]);
                    printf("now dp[%d] = %d\n",i,dp[i]);
                }
            }
        }
    }
    printArr(dp,money+1);
    return dp[money];
}

int main(){
    int money;
    int nCoin;
    scanf("%d", &money);
    scanf("%d",&nCoin);
    int coin[nCoin+5];
    
    for (int i =0;i<nCoin;i++){
        scanf("%d",&coin[i]);
    }

    int ans = minChangetoCoin(money, nCoin, coin);
}