#include<stdio.h>
#include<stdlib.h>
// #include<limits.h>

void initArrWith(int* arr, int n, int val){
    for (int i =0;i<=n;i++){
        arr[i] = val;
    }
}

int coinChange(int* coins, int nCoin, int money){
    int dp[money+1];
    int maxCoin[money+1];
    int whatCoin[5001];
    initArrWith(dp, money+1, 2e9);
    initArrWith(maxCoin, money+1, 0);
    initArrWith(whatCoin,5000,0);
    dp[0] = 0;
    for (int i = 1;i<= money;i++){
        // printf("\nCHECKING COINS AT %d\n\n",i);
        for (int j =0;j<nCoin;j++){
            // printf("Checking coin[%d] = %d\n",j,coins[j]);
            if (coins[j] <= i){
                // printf("Now cheking dp[%d - coins[%d]] = [%d-%d] = dp[%d] = %d\n",i,j,i,coins[j],i-coins[j],dp[i-coins[j]]);
                // printf("Check that %d + 1 < %d ?\n",dp[i-coins[j]],dp[i]);
                if (dp[i-coins[j]] + 1 <= dp[i]){
                    dp[i] = dp[i-coins[j]] + 1;
                    // printf("now dp[%d] = %d\n",i,dp[i]);
                    if (coins[j] > maxCoin[i]){ //เก็บเหรียญที่มีค่ามากที้่สุด ในการทำให้ได้เงินนั้น ๆ 
                        maxCoin[i] = coins[j];
                    }
                }
            }
        }
    }
    int backtrack = money;
    while (backtrack > 0){
        whatCoin[maxCoin[backtrack]] += 1;
        backtrack = backtrack - maxCoin[backtrack];
    }
    // for (int i =0;i<=money;i++){
    //     printf("%d\t",dp[i]);
    // }
    // printf("\n");
    for (int j=0;j<nCoin;j++){
        printf("%d: %d\n",coins[j], whatCoin[coins[j]]);
    }
    return dp[money];
    

}

int main(){
    int money;
    scanf("%d",&money);
    int nCoin;
    scanf("%d", &nCoin);
    int coins[nCoin];
    for (int i =0;i<nCoin;i++){
        scanf("%d",&coins[i]);
    }
    int ans = coinChange(coins, nCoin, money);
    // printf("%d",ans);
    return 0;
}