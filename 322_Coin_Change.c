#define min(a, b) (((a) < (b)) ? (a) : (b))
int coinChange(int* coins, int coinsSize, int amount) {
    int dp[amount + 1];
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        dp[i] = amount + 1;
        for (int c = 0; c < coinsSize; c++)
            if (i - coins[c] >= 0) 
                dp[i] = min(dp[i], 1 + dp[i - coins[c]]);
    }
    return (dp[amount] != (amount + 1)) ? dp[amount] : -1;
}