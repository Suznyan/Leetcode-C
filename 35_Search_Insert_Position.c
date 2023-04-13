#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* nums, int left, int right, int target) {
    if (left >= right) return nums[left] < target ? left + 1 : left;

    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return mid;
    if (nums[mid] < target)
        return binarySearch(nums, mid + 1, right, target);
    else
        return binarySearch(nums, left, mid - 1, target);
}

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    return binarySearch(nums, left, right, target);
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int target = 7;

    printf("%d\n", searchInsert(nums, sizeof(nums) / sizeof(*nums), target));

    return 0;
}