#include <stdio.h>
#include <stdlib.h>

int deleteGreatestValue(int **grid, int gridSize, int *gridColSize) {
    int ans = 0;
    int *countMap = malloc(sizeof(int) * 101);

    for (int r = 0; r < gridSize; r++) {
        int max = 0;
        for (int i = 1; i <= 100; i++) {
            countMap[i] = 0;
        }
        for (int c = 0; c < *gridColSize; c++) {
            if (grid[r][c] > max) max = grid[r][c];
            countMap[grid[r][c]]++;
        }
        int idx = 0;
        for (int i = 1; i <= max; i++) {
            for (int j = 0; j < countMap[i]; j++) {
                grid[r][idx++] = i;
            }
        }
    }

    free(countMap);
    countMap = NULL;

    for (int c = 0; c < *gridColSize; c++) {
        int max = 0;
        for (int r = 0; r < gridSize; r++) {
            if (grid[r][c] > max) max = grid[r][c];
        }
        ans += max;
    }

    return ans;
}

int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    int **grid = malloc(row * sizeof(*grid));
    for (int i = 0; i < row; i++) {
        grid[i] = malloc(col * sizeof(**grid));
    }

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            scanf("%d", &grid[r][c]);
        }
    }

    printf("\n%d\n", deleteGreatestValue(grid, row, &col));
    free(grid);
    grid = NULL;
    return 0;
}