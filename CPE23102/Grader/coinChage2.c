#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define COIN_COUNT 3

int coinChange(int coins[], int coinCount, int amount);
int coinChangeRecHelper(int coins[], int coinCount, int amount, int currAmount, int currNumCoins, int coinQty[]);

int main() {
    int coins[] = {1, 4, 7};
    int amount = 8;
    int result = coinChange(coins, COIN_COUNT, amount);
    printf("%d coins used:\n", result);

    return 0;
}

int coinChange(int coins[], int coinCount, int amount) {
    int coinQty[amount + 1];
    for (int i = 0; i <= amount; i++) {
        coinQty[i] = 0;
    }
    return coinChangeRecHelper(coins, coinCount, amount, amount, 0, coinQty);
}

int coinChangeRecHelper(int coins[], int coinCount, int amount, int currAmount, int currNumCoins, int coinQty[]) {
    if (currAmount < 0) return -1;

    if (currAmount == 0) {
        for (int i = 0; i < coinCount; i++) {
            if (coinQty[i] > 0) {
                printf("%d of %d\n", coinQty[i], coins[i]);
            }
        }
        return currNumCoins;
    }

    int minCoins = INT_MAX;
    for (int i = 0; i < coinCount; i++) {
        if (currAmount - coins[i] >= 0) {
            coinQty[i]++;
            int numCoinsTmp = coinChangeRecHelper(coins, coinCount, amount, currAmount - coins[i], currNumCoins + 1, coinQty);
            coinQty[i]--;

            if (numCoinsTmp != -1 && numCoinsTmp < minCoins) {
                minCoins = numCoinsTmp;
            }
        }
    }

    if (minCoins == INT_MAX) {
        minCoins = -1;
    }

    return minCoins;
}