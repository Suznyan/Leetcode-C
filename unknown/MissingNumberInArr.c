#include <stdio.h>
#include <stdlib.h>

int MissingNumber(int *arr, int n) {
    int sum = ((n + 1) * n) / 2;

    for (int i = 0; i < n - 1; i++) {
        sum = sum - arr[i];
    }
    return sum;
}

int main() {
    int n;    
    scanf("%d", &n);
    int arr[n - 1];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d ", &arr[i]);
    }
    printf("%d\n", MissingNumber(arr, n));
    return 0;
}