#include <stdio.h>
#include <stdlib.h>

int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 0) nums[i] = 0;
    }

    for (int i = 0; i < numsSize; i++) {
        int val = abs(nums[i]);
        if (val >= 1 && val <= numsSize) {
            if (nums[val - 1] > 0)
                nums[val - 1] *= -1;
            else if (nums[val - 1] == 0)
                nums[val - 1] = -1 * (numsSize + 1);
        }
    }

    for (int i = 1; i <= numsSize; i++) {
        if (nums[i - 1] >= 0) return i;
    }
    return numsSize + 1;
}

int main() {
    int size;
    scanf("%d", &size);
    int nums[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    printf("%d\n", firstMissingPositive(nums, size));

    return 0;
}