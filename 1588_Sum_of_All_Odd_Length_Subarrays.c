#include <stdio.h>
#include <stdlib.h>

int sumOddLengthSubarrays(int* arr, int arrSize) {
    int ans = 0;

    for (int i = 0; i < arrSize; i++) {
        ans += ((i + 1) * (arrSize - i) + 1) / 2 * arr[i];
    }

    return ans;
}

int main() {
    int input[] = {1,2};

    printf("%d",
           sumOddLengthSubarrays(input, (sizeof(input) / sizeof(*input))));

    return 0;
}