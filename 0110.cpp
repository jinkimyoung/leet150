

#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height;
        return dfs(root, height);
    }

    bool dfs(TreeNode *node, int &height)
    {
        if (!node)
        {
            height = -1;
            return true;
        }
        int left = 0, right = 0;
        if (!dfs(node->left, left) || !dfs(node->right, right)) return false;
        if (abs(left-right) > 1)    return false;
        height = 1 + max(left, right);
        return true;
    }
};