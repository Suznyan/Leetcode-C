#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize,
                   int** returnColumnSizes) {  
    *returnSize = matSize;
    *returnColumnSizes = malloc(sizeof(int) * matSize);
    for (int i = 0; i < matSize; i++) {
        (*returnColumnSizes)[i] = *matColSize;
    }

    int* map = malloc(101 * sizeof(int));
    for (int i = 1; i <= 100; i++) {
        map[i] = 0;
    }

    // From the top row
    for (int i = *matColSize - 1; i >= 0; i--) {
        int r = 0;
        int max = 0;
        int c = i;
        do {
            if (mat[r][c] > max) max = mat[r][c];
            map[mat[r][c]]++;
            r += 1;
            c += 1;
        } while (c < *matColSize && r < matSize);

        r = 0;
        c = i;
        for (int j = 1; j <= max; j++) {
            if (map[j] <= 0)
                continue;
            else
                for (int k = 0; k < map[j]; k++) {
                    mat[r][c] = j;
                    if (r + 1 < matSize && c + 1 < *matColSize) {
                        r += 1;
                        c += 1;
                    }
                }
        }

        for (int g = 0; g <= max; g++) {
            map[g] = 0;
        }
    }

    // From the side
    for (int i = 1; i < matSize; i++) {
        int r = i;
        int c = 0;
        int max = 0;

        do {
            if (mat[r][c] > max) max = mat[r][c];
            map[mat[r][c]]++;
            r += 1;
            c += 1;
        } while (c < *matColSize && r < matSize);

        r = i;
        c = 0;

        for (int j = 1; j <= max; j++) {
            if (map[j] <= 0)
                continue;
            else
                for (int k = 0; k < map[j]; k++) {
                    mat[r][c] = j;
                    if (r + 1 < matSize && c + 1 < *matColSize) {
                        r += 1;
                        c += 1;
                    }
                }
        }

        for (int g = 0; g <= max; g++) {
            map[g] = 0;
        }
    }

    free(map);
    map = NULL;

    return mat;
}

int main() {
    int row, col;
    scanf("%d %d", &row, &col);

    int** mat = malloc(sizeof(*mat) * row);
    for (int i = 0; i < row; i++) {
        mat[i] = malloc(sizeof(**mat) * col);
    }

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            scanf("%d", &mat[r][c]);
        }
    }

    int returnSize;
    int* returnColumnSizes;

    mat = diagonalSort(mat, row, &col, &returnSize, &returnColumnSizes);

    printf("Sorted\n");
    for (int r = 0; r < returnSize; r++) {
        for (int c = 0; c < *returnColumnSizes; c++) {
            printf("%d ", mat[r][c]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}