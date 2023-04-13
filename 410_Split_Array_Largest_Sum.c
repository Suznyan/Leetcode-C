#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) { return a > b ? a : b; }

int canSplit(int largest, int* nums, int numsSize, int k) {
    int subarray = 0;
    int currSum = 0;
    for (int i = 0; i < numsSize; i++) {
        currSum += nums[i];
        if (currSum > largest) {
            subarray++;
            currSum = nums[i];
        }
    }
    return (subarray + 1) <= k ? (subarray + 1) : 0;
}

int splitArray(int* nums, int numsSize, int k) {
    int maxSum = 0;
    int maxValue = 0;
    for (int i = 0; i < numsSize; i++) {
        maxValue = max(maxValue, nums[i]);
        maxSum += nums[i];
    }

    int res = maxSum;
    int L = maxValue, R = maxSum;
    while (L <= R) {
        int mid = L + ((R - L) / 2);
        if (canSplit(mid, nums, numsSize, k)) {
            res = mid;
            R = mid - 1;
        } else
            L = mid + 1;
    }
    return res;
}

int main() {
    int nums[] = {7, 2, 5, 10, 8};
    int k = 2;
    printf("%d\n", splitArray(nums, sizeof(nums) / sizeof(*nums), k));
    return 0;
}