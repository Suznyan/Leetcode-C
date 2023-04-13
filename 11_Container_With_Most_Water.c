#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }
int maxArea(int* height, int heightSize) {
    int res = 0, left = 0, right = heightSize - 1;
    while (left <= right) {
        res = max(res, (min(height[left], height[right]) * abs(left - right)));
        if (height[left] < height[right]) left++;
        else right--;
    }
    return res;
}