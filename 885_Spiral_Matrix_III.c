int** spiralMatrixIII(int rows, int cols, int rStart, int cStart,
                      int* returnSize, int** returnColumnSizes) {
    *returnSize = rows * cols;
    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    int** res = malloc((*returnSize) * sizeof *res);
    for (int i = 0; i < (*returnSize); i++) {
        res[i] = malloc(2 * sizeof **res);
        (*returnColumnSizes)[i] = 2;
    }
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // east, south, west, north
    int len = 0, d = 0, idx = 0; // move <len> steps in the <d> direction
    res[idx][0] = rStart, res[idx++][1] = cStart;
    while (idx < (*returnSize)) {
        if (d == 0 || d == 2) len++; // when move east or west, the length of path need plus 1
        for (int i = 0; i < len; i++) {
            rStart += dir[d][0];
            cStart += dir[d][1];
            if (rStart >= 0 && cStart >= 0 && rStart < rows && cStart < cols)
                res[idx][0] = rStart, res[idx++][1] = cStart;
        }
        d = (d + 1) % 4;
    }

    return res;
}
