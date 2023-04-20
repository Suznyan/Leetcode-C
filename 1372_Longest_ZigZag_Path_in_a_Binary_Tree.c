#define max(a, b) (((a) > (b)) ? (a) : (b))
void dfs(struct TreeNode* curr, int len, int* res, bool prev) {
    *res = max(*res, len);
    if (!curr) return;
    dfs(curr->right, prev ? (len + 1) : 0, res, false);
    dfs(curr->left, !prev ? (len + 1) : 0, res, true);
}

int longestZigZag(struct TreeNode* root) {
    int res = 0;
    dfs(root->left, 0, &res, true);
    dfs(root->right, 0, &res, false);
    return res;
}