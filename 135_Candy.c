#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return a > b ? a : b; }
int candy(int* ratings, int ratingsSize) {
    int res = 0;
    int LR[ratingsSize];
    int RL[ratingsSize];
    for (int i = 0; i < ratingsSize; i++) {
        LR[i] = 1;
        if (i > 0 && ratings[i] > ratings[i - 1])
            LR[i] = LR[i - 1] + 1;
        else if (i > 0 && ratings[i] <= ratings[i - 1])
            LR[i] = 1;
    }
    for (int i = ratingsSize - 1; i >= 0; i--) {
        RL[i] = 1;
        if (i < ratingsSize - 1 && ratings[i] > ratings[i + 1])
            RL[i] = RL[i + 1] + 1;
        else if (i < ratingsSize - 1 && ratings[i] <= ratings[i + 1])
            RL[i] = 1;
    }

    for (int i = 0; i < ratingsSize; i++) {
        res += max(LR[i], RL[i]);
    }
    return res;
}

int main() { return 0; }