int dfs(int n, int *memo, int depth) {
    if (depth > n) return 0;
    if (depth == n) return 1;
    if (memo[depth] != 0) return memo[depth];
    return memo[depth] = dfs(n, memo, depth + 1) + dfs(n, memo, depth + 2);
}

int climbStairs(int n) {
    int memo[46] = {0};
    return dfs(n, &memo[0], 0);
}