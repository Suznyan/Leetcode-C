#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }

/*
int trap(int* height, int heightSize) {
    int *maxLeft = malloc(heightSize * sizeof(int)),
        *maxRight = malloc(heightSize * sizeof(int));

    maxLeft[0] = 0, maxRight[heightSize - 1] = 0;

    for (int i = 1; i < heightSize; i++)
        maxLeft[i] = max(height[i - 1], maxLeft[i - 1]);
    for (int i = heightSize - 2; i >= 0; i--)
        maxRight[i] = max(maxRight[i + 1], height[i + 1]);

    int res = 0;
    for (int i = 0; i < heightSize; i++)
        if (min(maxLeft[i], maxRight[i]) - height[i] > 0)
            res += min(maxLeft[i], maxRight[i]) - height[i];

    free(maxLeft), free(maxRight);
    maxLeft = NULL, maxRight = NULL;

    return res;
}
*/

int trap(int* height, int heightSize) {
    if (!heightSize) return 0;
    int *left = height, *right = left + heightSize - 1;
    int maxL = *left, maxR = *right;
    int res = 0;

    while (left < right)
        if (maxL < maxR) {
            left++;
            maxL = max(maxL, *left);
            res += maxL - *left;
        } else {
            right--;
            maxR = max(maxR, *right);
            res += maxR - *right;
        }

    return res;
}

int main() {
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    printf("%d\n", trap(height, sizeof(height) / sizeof(*height)));
    return 0;
}