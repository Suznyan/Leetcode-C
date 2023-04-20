void merge(int *arr, int l, int m, int r) {
    int left_length = m - l + 1;
    int right_length = r - m;

    int tempL[left_length], tempR[right_length];

    for (int i = 0; i < left_length; i++) tempL[i] = arr[l + i];
    for (int i = 0; i < right_length; i++) tempR[i] = arr[m + 1 + i];

    for (int i = 0, j = 0, k = l; k <= r; k++) {
        if ((i < left_length) && (j >= right_length || tempL[i] <= tempR[j])) {
            arr[k] = tempL[i++];
        } else
            arr[k] = tempR[j++];
    }
}

void mSort_recursion(int *arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mSort_recursion(arr, l, m);
    mSort_recursion(arr, m + 1, r);
    merge(arr, l, m, r);
}

void mSort(int *arr, int size) { mSort_recursion(arr, 0, size - 1); }

int findKthLargest(int *nums, int numsSize, int k) {
    mSort(nums, numsSize);
    return nums[numsSize - k];
}