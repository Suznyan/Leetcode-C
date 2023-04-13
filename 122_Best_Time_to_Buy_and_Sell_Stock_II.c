#include <limits.h>
int maxProfit(int* prices, int pricesSize) {
    int minprice = INT_MAX;
    int finalprofit = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minprice) minprice = prices[i];
        if (i > 0 && i < pricesSize - 1 && prices[i] - minprice > 0 &&
            prices[i + 1] < prices[i]) {
            finalprofit += prices[i] - minprice;
            minprice = INT_MAX;
        }
        if (i == pricesSize - 1 && prices[i] - minprice > 0)
            finalprofit += prices[i] - minprice;
    }
    return finalprofit;
}

int main(){
    return 0;
}