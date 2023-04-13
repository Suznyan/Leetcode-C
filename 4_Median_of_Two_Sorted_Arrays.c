#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2,
                              int nums2Size) {
    int combine[nums1Size + nums2Size];
    int idx = 0;
    for (size_t i = 0; i < nums1Size + nums2Size; i++) {
        if (i < nums1Size)
            combine[i] = nums1[i];
        else
            combine[i] = nums2[idx++];
    }

    for (int i = 0; i < nums1Size + nums2Size; i++) {
        for (int j = i + 1; j < nums1Size + nums2Size; j++) {
            if (combine[i] > combine[j]) swap(&combine[i], &combine[j]);
        }
    }

    if ((nums1Size + nums2Size) % 2 == 0) {
        int l = (nums1Size + nums2Size) / 2;
        return (combine[l] + combine[l - 1]) / 2.00;
    } else
        return combine[(nums1Size + nums2Size) / 2];
}

int main() {
    int size1, size2;
    scanf("%d %d", &size1, &size2);
    int* nums1 = malloc(size1 * sizeof(int));
    int* nums2 = malloc(size2 * sizeof(int));

    for (int i = 0; i < size1; i++) {
        scanf("%d", &nums1[i]);
    }

    for (int i = 0; i < size2; i++) {
        scanf("%d", &nums2[i]);
    }

    double median = findMedianSortedArrays(nums1, size1, nums2, size2);

    printf("%5f\n", median);

    return 0;
}