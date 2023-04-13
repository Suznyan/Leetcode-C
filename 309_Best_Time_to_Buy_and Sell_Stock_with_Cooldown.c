#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) return 0;
    int hold = INT_MAX;
    int sold = INT_MIN;
    int rest = 0;

    for (int i = 0; i < pricesSize; i++) {
        
    
    }

    
}

int main() {
    int prices[] = {1, 2, 3, 0, 2};
    int n = sizeof(prices) / sizeof(*prices);

    printf("%d\n", maxProfit(prices, n));
    return 0;
}