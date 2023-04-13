#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) { return a > b ? a : b; }
int minDistance(int* houses, int housesSize, int k) {
    int maxV = 0;
    for (int i = 0; i < housesSize; i++) {
        maxV = max(maxV, houses[i]);
    }
    int* count = malloc((maxV + 1) * sizeof(int));
    for (int i = 0; i <= maxV; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < housesSize; i++) {
        count[houses[i]]++;
    }
    int idx = 0;
    for (int i = 0; i <= maxV; i++) {
        for (int j = 0; j < count[i]; j++) {
            houses[idx++] = i;
        }
    }

    int kV[k];
    for (int i = 0; i < k; i++) {
        int pos = housesSize / 2;
        int temp = 0;
        for (int j = 0; j < housesSize; j++) {
        }
    }

    return;
}
int main() {
    int house[] = {2, 3, 5, 12, 18};
    int k = 2;

    printf("%d\n", minDistance(house, sizeof(house) / sizeof(*house), k));
    return 0;
}