#include <stdio.h>
#include <stdlib.h>

int numIdenticalPairs(int* nums, int numsSize) {
    int pairCount = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == nums[i]) pairCount++;
        }
    }

    return pairCount;
}

int main() {
    int nums[] = {1,2,3};

    printf("%d", numIdenticalPairs(nums, sizeof(nums) / sizeof(*nums)));
    return 0;
}