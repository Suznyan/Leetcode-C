#include <limits.h>
int max(int a, int b) { return a > b ? a : b; }
int maxSubArray(int* nums, int numsSize) {
    int currMax = 0, best = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        currMax = max(nums[i], currMax + nums[i]);
        best = max(best, currMax);
    }
    return best;
}