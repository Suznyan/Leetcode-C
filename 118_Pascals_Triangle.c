int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** res = malloc(numRows * sizeof *res);
    *returnSize = numRows;
    *returnColumnSizes = malloc(numRows * sizeof(int));
    for (int i = 0; i < numRows; i++) {
        res[i] = malloc((i + 1) * sizeof **res);
        (*returnColumnSizes)[i] = i + 1;
    }

    for (int i = 0; i < numRows; i++)
        for (int j = 0; j < i + 1; j++)
            if (j == 0 || j == i)
                res[i][j] = 1;
            else
                res[i][j] = res[i - 1][j] + res[i - 1][j - 1];

    return res;
}