#include <stdio.h>
#include <stdlib.h>

int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* ans = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int f = 0, s = 1;

    for (int i = 0; i < n; i++) {
        ans[f] = nums[i];
        ans[s] = nums[i + n];
        f += 2;
        s += 2;
    }

    return ans;
}

int main() {
    int nums[] = {1,2,3,4,4,3,2,1};
    int n = 4;
    int returnsize;
    int* ans = shuffle(nums, sizeof(nums) / sizeof(nums[0]), n, &returnsize);
    
    for (int i = 0; i < returnsize; i++) {
        printf("%d ", ans[i]);
    }

    free(ans);
    
    return 0;
}