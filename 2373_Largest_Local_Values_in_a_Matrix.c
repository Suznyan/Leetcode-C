#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define maxx(a, b, c) (max((a), max((b), (c))))

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize,
                   int** returnColumnSizes) {
    int buf[3] = {0};  // circular buffer to keep 3 recent values

    int col_len = gridColSize[0];  // colum length. always same?

    int** ret = (int**)malloc(gridSize * sizeof(int*));  // return matrix
    for (int i = 0; i < gridSize; i++)
        ret[i] = (int*)malloc((col_len - 2) * sizeof(int));

    for (int i = 0; i < gridSize; i++)  // first find max horizontally
    {
        buf[0] = grid[i][0];  // store first 2 values in buffer
        buf[1] = grid[i][1];

        for (int j = 2; j < col_len; j++)  // for each element in row
        {
            buf[j % 3] = grid[i][j];  // add 3rd element to buffer
            ret[i][j - 2] = maxx(buf[0], buf[1], buf[2]);  // get max
        }
    }

    for (int j = 0; j < col_len - 2; j++)  // now do max vertically
    {
        buf[0] = ret[0][j];  // add first two elements to buf
        buf[1] = ret[1][j];

        for (int i = 2; i < gridSize; i++)  // for each vertical element
        {
            buf[i % 3] = ret[i][j];                        // add it to buffer
            ret[i - 2][j] = maxx(buf[0], buf[1], buf[2]);  // get max
        }
    }

    free(ret[gridSize - 1]);  // these were only needed for horizontal part
    free(ret[gridSize - 2]);

    *returnColumnSizes = (int*)malloc((col_len - 2) * sizeof(int));
    for (int i = 0; i < col_len - 2; i++) (*returnColumnSizes)[i] = col_len - 2;
    *returnSize = gridSize - 2;
    return ret;
}

int main(int* argc, char** argv) {
    int grid[] = {{9, 9, 8, 1}, {5, 6, 2, 6}, {8, 2, 6, 4}, {6, 2, 2, 2}};
    int returnSize;
    int *returnColumnSizes;
    int** ans = largestLocal(grid, sizeof(grid) / sizeof(*grid), sizeof(grid) / sizeof(*grid), &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes; i++) {
            printf("%d ", ans[i][j]);
        }
        printf("]");
    }
    printf("]");

    free(ans);

    return 0;
}