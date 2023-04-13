int countKDifference(int* nums, int numsSize, int k) {
    int res = 0;
    int* count = malloc(101 * sizeof(int));
    for (int i = 0; i < 101; i++) count[i] = 0;
    for (int i = 0; i < numsSize; i++) count[nums[i]]++;
    for (int i = k + 1; i < 101; i++) res += count[i] * count[i - k];
    free(count);
    count = NULL;
    return res;
}