#include <stdio.h>
#include <stdlib.h>

int* decompressRLElist(int* nums, int numsSize, int* returnSize) {
    int size = 0;
    for (int i = 0; i < numsSize; i += 2) {
        size += nums[i];
    }

    int* ans = malloc(sizeof(int) * size);
    *returnSize = size;

    int index = 0;

    for (int i = 0; i < numsSize; i += 2) {
        for (int j = 0; j < nums[i]; j++) {
            ans[index] = nums[i + 1];
            index++;
        }
    }
    return ans;
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int returnSize;
    int* ans =
        decompressRLElist(nums, sizeof(nums) / sizeof(*nums), &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }

    free(ans);

    return 0;
}