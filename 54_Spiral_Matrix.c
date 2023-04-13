#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize,
                 int* returnSize) {
    *returnSize = matrixSize * *matrixColSize;
    int *res = malloc(*returnSize * sizeof(int)), k = 0;
    int idx = 0;
    int top = 0, right = *matrixColSize - 1, bottom = matrixSize - 1, left = 0;
    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
            res[idx++] = matrix[top][i];
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            res[idx++] = matrix[i][right];
        }
        right--;

        if (top <= bottom)
            for (int i = right; i >= left; i--) {
                res[idx++] = matrix[bottom][i];
            }
        bottom--;

        if (left <= right)
            for (int i = bottom; i >= top; i--) {
                res[idx++] = matrix[i][left];
            }
        left++;
    }

    return res;
}

int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    int** matrix = malloc(row * sizeof *matrix);
    for (int i = 0; i < row; i++) {
        matrix[i] = malloc(col * sizeof **matrix);
    }

    int num = 1;
    for (int R = 0; R < row; R++) {
        for (int C = 0; C < col; C++) {
            matrix[R][C] = num++;
            printf("%d\t", matrix[R][C]);
        }
        printf("\n");
    }
    printf("\n");

    int ColSize = col;
    int returnSize;

    int* new = spiralOrder(matrix, row, &ColSize, &returnSize);

    printf("Spiral traversal:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", new[i]);
    }
    printf("\n\n");

    free(new);
    new = NULL;

    return 0;
}