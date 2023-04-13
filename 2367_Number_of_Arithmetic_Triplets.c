#include <stdio.h>
#include <stdlib.h>

int arithmeticTriplets(int* nums, int numsSize, int diff) {
    int ans;

    for (int i = 0; i < numsSize - 2; i++) {
        for (int j = i + 1; j < numsSize - 1; j++) {
            if (nums[j] - nums[i] == diff) {
                for (int k = j + 1; k < numsSize; k++) {
                    if (nums[k] - nums[j] == diff)
                        ans++;
                    else if (nums[k] - nums[j] > diff)
                        break;
                }
            } else if (nums[j] - nums[i] > diff)
                break;
        }
    }

    return ans;
}

int main() {
    int input[] = {4,5,6,7,8,9};
    int diff = 2;
    printf("%d",
           arithmeticTriplets(input, sizeof(input) / sizeof(*input), diff));
    return 0;
}