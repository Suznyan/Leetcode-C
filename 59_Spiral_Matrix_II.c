int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    int** res = malloc(n * sizeof(*res));
    for (int i = 0; i < n; i++) {
        res[i] = malloc(n * sizeof(**res));
    }
    *returnColumnSizes = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }

    int num = 1, top = 0, right = n, bottom = n, left = 0;
    while (num <= n * n) {
        for (int i = left; i < right; i++) {
            res[top][i] = num++;
        }
        top++;

        for (int i = top; i < bottom; i++) {
            res[i][right - 1] = num++;
        }
        right--;

        if (right - 1 >= left)
            for (int i = right - 1; i >= left; i--) {
                res[bottom - 1][i] = num++;
            }
        bottom--;

        if (bottom - 1 >= top)
            for (int i = bottom - 1; i >= top; i--) {
                res[i][left] = num++;
            }
        left++;
    }

    return res;
}