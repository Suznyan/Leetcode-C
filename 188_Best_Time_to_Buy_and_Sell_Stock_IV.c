#include <limits.h>
int min(int a, int b) { return a > b ? b : a; }
int max(int a, int b) { return a > b ? a : b; }
int maxProfit(int k, int *prices, int pricesSize) {
    int *buy = malloc((k + 1) * sizeof(int));
    int *profit = malloc((k + 1) * sizeof(int));
    for (int i = 0; i <= k; i++) {
        buy[i] = INT_MAX;
        profit[i] = INT_MIN;
    }
    for (int i = 0; i < pricesSize; i++) {
        for (int j = 1; j <= k; j++) {
            buy[j] = min(buy[j], prices[i] - profit[j - 1]);
            profit[j] = max(profit[j], prices[i] - buy[j]);
        }
    }
    return profit[k];
}