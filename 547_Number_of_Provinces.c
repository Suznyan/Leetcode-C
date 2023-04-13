void dfs(int** adjacentMatrix, int matrixSize, int index, int* visited) {
    visited[index] = 1;
    for (int i = 0; i < matrixSize; i++) {
        if (adjacentMatrix[index][i] && !visited[i]) {
            dfs(adjacentMatrix, matrixSize, i, visited);
        }
    }
}

int findCircleNum(int** M, int MSize, int* MColSize) {
    int circles = 0;
    int visited[MSize];
    for (int i = 0; i < MSize; i++) visited[i] = 0;
    for (int i = 0; i < MSize; ++i) {
        if (!visited[i]) {
            circles++;
            dfs(M, MSize, i, &visited);
        }
    }
    return circles;
}