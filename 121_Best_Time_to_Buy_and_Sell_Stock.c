#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return a > b ? a : b; }
int maxProfit(int* prices, int pricesSize) {
    int *L = prices, *R = L + 1;
    int res = 0;
    while (R < &prices[pricesSize]) {
        if (*L < *R)
            res = max(res, *R - *L);
        else
            L = R;
        R++;
    }
    return res;
}

int main() {
    int prices[] = {3, 2, 6, 5, 0, 3};
    int size = sizeof(prices) / sizeof(*prices);
    printf("%d", maxProfit(prices, size));
    return 0;
}