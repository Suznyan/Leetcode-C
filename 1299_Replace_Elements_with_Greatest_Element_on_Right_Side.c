int max(int a, int b) { return a > b ? a : b; }
int* replaceElements(int* arr, int arrSize, int* returnSize) {
    int* res = malloc(arrSize * sizeof(int));
    *returnSize = arrSize;  
    int currMax = -1;
    for (int i = arrSize - 1; i >= 0; i--) {
        res[i] = currMax;
        currMax = max(arr[i], currMax);
    }
    return res;
}