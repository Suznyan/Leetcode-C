#include <stdio.h>
#include <stdlib.h>
/*
int maxProductDifference(int* nums, int numsSize) {
    int ans = 0;
    int maxVal = 0;
    int* sorted = malloc(sizeof(int) * numsSize);

    int* countMap = malloc(10001 * sizeof(int));

    for (int i = 0; i <= 10000; i++) {
        countMap[i] = 0;
    }

    for (int i = 0; i < numsSize; i++) {
        countMap[nums[i]]++;
        if (nums[i] > maxVal) maxVal = nums[i];
    }
    int idx = 0;
    for (int i = 1; i <= maxVal; i++) {
        for (int j = 0; j < countMap[i]; j++) {
            sorted[idx++] = i;
        }
    }

    ans =
        (sorted[numsSize - 1] * sorted[numsSize - 2]) - (sorted[0] *
        sorted[1]);
    free(sorted);
    free(countMap);
    sorted = NULL;
    countMap = NULL;

    return ans;
}
*/
int maxProductDifference(int* nums, int numsSize) {
    // find 4 numbers, 2 largest (A, B) and 2 smallest (C, D)
    // the maximum product difference is always (AB) - (CD)

    int larger, largest, smaller, smallest;
    int i, j;
    larger = largest = 0;
    smaller = smallest = 10001;

    for (i = 0; i < numsSize; i++) {
        j = nums[i];

        if (j > largest) {
            larger = largest;
            largest = j;
        } else if (j > larger) {
            larger = j;
        }

        if (j < smallest) {
            smaller = smallest;
            smallest = j;
        } else if (j < smaller) {
            smaller = j;
        }
    }

    return ((larger * largest) - (smaller * smallest));
}
int main() {
    int size = 0;
    scanf("%d", &size);
    int* nums = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    int ans = maxProductDifference(nums, size);

    printf("%d", ans);

    return 0;
}