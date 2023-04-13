#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseInGroups(int *arr, int n, int k) {
    int remainder = n % k;
    int i = 0;
    int RI = 0;
    int reversed[n];
    while (i < n - remainder) {
        for (int j = k + i; j > i; j--) {
            reversed[RI] = arr[j - 1];
            RI++;
        }
        i = i + k;
    }

    for (i = n - 1; i >= n - remainder; i--) {
        reversed[RI] = arr[i];
        RI++;
    }
    memcpy(arr, reversed, sizeof(reversed));
}

int main() {
    int arr[] = {1,2,3,4,5};

    reverseInGroups(arr, 5, 3);

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}