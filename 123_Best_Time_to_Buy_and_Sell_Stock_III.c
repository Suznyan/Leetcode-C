#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { return a > b ? b : a; }
int max(int a, int b) { return a > b ? a : b; }

int maxProfit(int* prices, int pricesSize) {
    if (!pricesSize) return 0;
    int buy1 = INT_MAX, buy2 = INT_MAX, profit1 = INT_MIN, profit2 = INT_MIN;
    for (int i = 0; i < pricesSize; i++) {
        buy1 = min(buy1, prices[i]);
        profit1 = max(profit1, prices[i] - buy1);
        buy2 = min(buy2, prices[i] - profit1);
        profit2 = max(profit2, prices[i] - buy2);
    }
    return profit2;
}

int main() {
    int prices[] = {3,3,5,0,0,3,1,4};

    printf("%d\n", maxProfit(prices, sizeof(prices) / sizeof(*prices)));
    return 0;
}