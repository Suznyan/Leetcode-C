void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void dfs(int* nums, int numsSize, int*** permuted, int* returnSize,
         int** returnColumnSizes, int curr) {
    int i = 0;
    if (curr >= numsSize - 1) {
        *returnSize += 1;
        (*returnColumnSizes)[*returnSize - 1] = numsSize;

        (*permuted)[*returnSize - 1] = malloc(numsSize * sizeof(int));
        for (i = 0; i < numsSize; ++i)
            (*permuted)[*returnSize - 1][i] = nums[i];
        return;
    }

    // enumerate each element for current position
    for (i = curr; i < numsSize; ++i) {
        swap(nums + curr, nums + i);
        dfs(nums, numsSize, permuted, returnSize, returnColumnSizes, curr + 1);
        swap(nums + curr, nums + i);
    }
}

// Time O(N!) Space O(N)
int** permute(int* nums, int numsSize, int* returnSize,
              int** returnColumnSizes) {
    *returnSize = 1;
    for (int i = 1; i <= numsSize; ++i) (*returnSize) *= i;

    int** permutations = malloc(*returnSize * sizeof(int));
    *returnColumnSizes = malloc(*returnSize * sizeof(int));

    *returnSize = 0;
    dfs(nums, numsSize, &permutations, returnSize, returnColumnSizes, 0);

    return permutations;
}