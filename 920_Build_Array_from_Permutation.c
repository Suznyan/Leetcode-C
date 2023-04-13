int *buildArray(int *nums, int numsSize, int *returnSize) {
    *returnSize = numsSize;
    int n = numsSize;
    for (int i = 0; i < n; i++) nums[i] = nums[i] + (nums[nums[i]] % n) * n;

    for (int j = 0; j < n; j++) nums[j] = nums[j] / n;

    return nums;
}