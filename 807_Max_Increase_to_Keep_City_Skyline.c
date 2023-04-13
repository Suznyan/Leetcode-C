#include <stdio.h>
#include <stdlib.h>

int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize) {
    int ans = 0;
    int* rowMax = malloc(gridSize * sizeof(int));
    int* colMax = malloc(*gridColSize * sizeof(int));

    for (int i = 0; i < gridSize; i++) {
        rowMax[i] = 0;
        colMax[i] = 0;
    }

    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < *gridColSize; c++) {
            if (grid[r][c] > rowMax[r]) rowMax[r] = grid[r][c];
            if (grid[r][c] > colMax[c]) colMax[c] = grid[r][c];
        }
    }

    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < *gridColSize; c++) {
            int min = 101;
            if (rowMax[r] < min) min = rowMax[r];
            if (colMax[c] < min) min = colMax[c];
            ans += min - grid[r][c];
        }
    }

    free(rowMax);
    free(colMax);
    rowMax = NULL;
    colMax = NULL;

    return ans;
}

int main() {
    int row = 4, col = 4;
    int** grid = malloc(row * sizeof(*grid));
    for (int i = 0; i < row; i++) {
        grid[i] = malloc(col * sizeof(**grid));
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int ans = maxIncreaseKeepingSkyline(grid, row, &col);
    printf("%d\n", ans);

    return 0;
}