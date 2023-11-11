#include<stdio.h>

void coinRow(){

}

int main(){
    int coin[] = {1,5,8,4,6,2,4,7,20,64,21,84981,1};
    int n = (int)sizeof(coinRow) / (int)sizeof(int);
    int coinMax[n+1];
    coinRow(coin,n);
    return 0;
}