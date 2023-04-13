#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *subarraySum(int *arr, int n, int s) {
    // if (s == 0) {
    //     return -1;
    // }
    int ans[2];
    int sum = arr[0];
    int startIn = 0, endIn = 1;
    while (endIn <= n) {
        if (sum == s) {
            ans[0] = startIn+1;
            ans[1] = endIn;
            return ans;
        } 
        if (sum > s) {
            sum -= arr[startIn++];
        } else {
            sum += arr[endIn++];
        }
    }
}

int main(int *argc, char **argv) {
    int n, s;
    scanf("%d %d", &n, &s);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d,", &arr[i]);
    }

    int *res = subarraySum(arr, n, s);
    for (int i = 0; i < sizeof(arr); i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}