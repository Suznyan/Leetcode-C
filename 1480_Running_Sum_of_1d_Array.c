#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        ans[i] = sum;
    }

    return ans;
}

int main() {
    int nums[] = {3, 1, 2, 10, 1};
    int returnsize;
    int* ans = runningSum(nums, sizeof(nums) / sizeof(*nums), &returnsize);

    for (int i = 0; i < returnsize; i++) {
        printf("%d ", ans[i]);
    }

    free(ans);

    return 0;
}