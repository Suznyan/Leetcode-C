#include <stdio.h>
#include <stdlib.h>

int maximumWealth(int **accounts, int accountsSize, int *accountsColSize) {
    int maxWealth = 0;

    for (int i = 0; i < accountsSize; i++) {
        int temp = 0;
        for (int j = 0; j < *accountsColSize; j++) {
            temp += accounts[i][j];
            if (temp > maxWealth) maxWealth = temp;
        }
    }

    return maxWealth;
}

int main(int *argc, char **argv) {
    int m = 2;
    int n = 3;
    int **acc;
    acc = malloc(m * sizeof *acc);
    for (int i = 0; i < m; i++) {
        acc[i] = malloc(n * sizeof *acc[i]);
    }
    int *a[] = {{1, 2, 3}, {3, 2, 1}};

    printf("%d", maximumWealth(acc, m, &n));

    for (int i = 0; i < m; i++) {
        free(acc[i]);
    }
    free(acc);
    return 0;
}