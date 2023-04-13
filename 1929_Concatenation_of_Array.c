#include <stdio.h>
#include <stdlib.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(sizeof(int) * numsSize * 2);
    *returnSize = 2 * numsSize;
    int idx = 0;
    for (int i = 0; i < 2; i++) 
        for (int i = 0; i < numsSize; i++)
            ans[idx++] = nums[i];
    
    return ans;
}

int main() {
    int arr[] = {};
    int returnSize;

    int* ans = getConcatenation(arr, sizeof(arr) / sizeof(*arr), &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}