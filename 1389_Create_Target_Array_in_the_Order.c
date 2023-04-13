#include <stdio.h>
#include <stdlib.h>

int* createTargetArray(int* nums, int numsSize, int* index, int indexSize,
                       int* returnSize) {
    int* ans = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        ans[i] = -1;
    }

    for (int i = 0; i < numsSize; i++) {
        if (ans[index[i]] >= 0) {
            for (int j = numsSize - 1; j > index[i]; j--) {
                ans[j] = ans[j - 1];
            }
            ans[index[i]] = nums[i];
        }
        ans[index[i]] = nums[i];
    }

    return ans;
}

int main() { return 0; }
