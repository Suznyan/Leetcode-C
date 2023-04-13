#include <stdio.h>
#include <stdlib.h>

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++) {
        ans[i] = 0;

        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] > nums[j]) ans[i]++;
        }

        if (i > 0)
            for (int k = i - 1; k >= 0; k--) {
                if (nums[i] > nums[k]) ans[i]++;
            }
    }

    return ans;
}

int main() { return 0; }