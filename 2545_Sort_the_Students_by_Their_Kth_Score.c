#include <stdio.h>
#include <stdlib.h>

/*
There is a class with m students and n exams. You are given a 0-indexed m x n
integer matrix score, where each row represents one student and score[i][j]
denotes the score the ith student got in the jth exam. The matrix score contains
distinct integers only.

You are also given an integer k. Sort the students (i.e., the rows of the
matrix) by their scores in the kth (0-indexed) exam from the highest to the
lowest.

Return the matrix after sorting it.
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** sortTheStudents(int** score, int scoreSize, int* scoreColSize, int k,
                      int* returnSize, int** returnColumnSizes) {
    int** sorted = malloc(scoreSize * sizeof(*score));
    for (int i = 0; i < scoreSize; i++) {
        sorted[i] = malloc(*scoreColSize * sizeof(**score));
    }

    int* map = malloc(sizeof(int) * 100001);
    for (int i = 0; i <= 100000; i++) {
        map[i] = -1;
    }

    int max = 0;
    // Compute
    for (int r = 0; r < scoreSize; r++) {
        map[score[r][k]] = r;
        if (score[r][k] > max) max = score[r][k];
    }

    int idx = scoreSize - 1;
    for (int i = 1; i <= max; i++) {
        if (map[i] != -1) {
            for (int c = 0; c < *scoreColSize; c++) {
                sorted[idx][c] = score[map[i]][c];
            }
            idx--;
        } else
            continue;
    }
    //

    free(map);
    map = NULL;

    *returnSize = scoreSize;
    *returnColumnSizes = malloc(sizeof(int) * scoreSize);
    for (int i = 0; i < scoreSize; i++) {
        (*returnColumnSizes)[i] = *scoreColSize;
    }

    return sorted;
}

int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    int** score = malloc(row * sizeof(*score));
    for (int i = 0; i < row; i++) {
        score[i] = malloc(col * sizeof(**score));
    }

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            scanf("%d", &score[r][c]);
        }
    }

    int k;
    printf("k = ");
    scanf("%d", &k);

    printf("Input:\n");
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            printf("%d ", score[r][c]);
        }
        printf("\n");
    }
    printf("\n");

    int returnSize = row;
    int* returnColumnSizes;

    score =
        sortTheStudents(score, row, &col, k, &returnSize, &returnColumnSizes);

    printf("Result: \n");
    for (int r = 0; r < returnSize; r++) {
        for (int c = 0; c < *returnColumnSizes; c++) {
            printf("%d ", score[r][c]);
        }
        printf("\n");
    }
    printf("\n");

    free(score);
    score = NULL;
    free(returnColumnSizes);
    returnColumnSizes = NULL;

    return 0;
}