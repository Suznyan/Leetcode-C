#define max(a, b) (((a) > (b)) ? (a) : (b))
struct my_data {
    TreeNode *node;
    unsigned long long int num, level;
};

class Solution {
   public:
    int widthOfBinaryTree(TreeNode *root) {
        queue<my_data> q;
        int res = 0;
        q.push(my_data{root, 0, 0});
        unsigned long long int prevLevel = 0, prevNum = 0;
        while (!q.empty()) {
            my_data temp = q.front();
            q.pop();
            if (temp.level > prevLevel) {
                prevLevel = temp.level;
                prevNum = temp.num;
            }

            res = max(res, (temp.num - prevNum + 1));
            if (temp.node->left != NULL)
                q.push(my_data{temp.node->left, 2 * temp.num + 1, temp.level + 1});
            if (temp.node->right != NULL)
                q.push(my_data{temp.node->right, 2 * temp.num + 2, temp.level + 1});
        }

        return res;
    }
};