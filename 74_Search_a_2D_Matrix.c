#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int potiental_row = 0;
    int different = pow(10, 4);
    for (int r = 0; r < matrixSize; r++) {
        if (target > matrix[matrixSize - 1 - r][0] &&
            target - matrix[matrixSize - 1 - r][0] < different) {
            potiental_row = matrixSize - 1 - r;
            different = target - matrix[matrixSize - 1 - r][0];
        }
        if (matrix[matrixSize - 1 - r][0] == target) return true;
    }

    for (int c = 0; c < *matrixColSize; c++) {
        if (matrix[potiental_row][c] == target) return true;
    }
    return false;
}

int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    int** matrix = malloc(row * sizeof *matrix);
    for (int i = 0; i < row; i++) {
        matrix[i] = malloc(col * sizeof **matrix);
    }

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            scanf("%d", &matrix[r][c]);
        }
    }
    int target;
    printf("target: ");
    scanf("%d", &target);

    printf(searchMatrix(matrix, row, &col, target) ? "true" : "false");

    return 0;
}