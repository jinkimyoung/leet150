
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode *node, long lMin, long lMax)
    {
        if (!node)  return true;
        if (node->val <= lMin || node->val >= lMax)  return false;

        return dfs(node->left, lMin, node->val) && dfs(node->right, node->val, lMax);
    }
};
