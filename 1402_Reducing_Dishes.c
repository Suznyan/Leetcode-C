#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) { return a > b ? a : b; }
int maxSatisfaction(int *satisfaction, int satisfactionSize) {
    int *negativeCount = malloc(1001 * sizeof(int));
    int *positiveCount = malloc(1001 * sizeof(int));

    for (int i = 0; i <= 1000; i++) {
        negativeCount[i] = 0;
        positiveCount[i] = 0;
    }

    int maxPositive = 0, maxNegative = 0;
    for (int i = 0; i < satisfactionSize; i++) {
        if (satisfaction[i] >= 0) {
            positiveCount[satisfaction[i]]++;
            maxPositive = max(maxPositive, satisfaction[i]);
        } else {
            negativeCount[abs(satisfaction[i])]++;
            maxNegative = max(maxNegative, abs(satisfaction[i]));
        }
    }

    int idx = 0;
    for (int i = maxNegative; i > 0; i--) {
        for (int j = 0; j < negativeCount[i]; j++) {
            satisfaction[idx++] = 0 - i;
        }
    }
    for (int i = 0; i <= maxPositive; i++) {
        for (int j = 0; j < positiveCount[i]; j++) {
            satisfaction[idx++] = i;
        }
    }

    int sum = 0;
    int pos;
    for (int i = satisfactionSize - 1; i >= 0; i--) {
        sum += satisfaction[i];
        if (sum < 0)
            break;
        else
            pos = i;
    }

    int res = 0;
    int time = 1;
    for (int i = pos; i < satisfactionSize; i++) {
        res += (time++) * satisfaction[i];
    }

    free(negativeCount);
    free(positiveCount);
    negativeCount = NULL;
    positiveCount = NULL;

    return res > 0 ? res : 0;
}