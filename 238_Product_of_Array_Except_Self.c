#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* res = malloc(numsSize * sizeof(int));
    int preFix = 1;
    for (int i = 0; i < numsSize; i++) {
        res[i] = preFix;
        preFix *= nums[i];
    }

    int postFix = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        res[i] *= postFix;
        postFix *= nums[i];
    }

    *returnSize = numsSize;
    return res;
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int count = sizeof(nums) / sizeof(*nums);
    int returnSize;
    int* res = productExceptSelf(nums, count, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}