
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


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
    
    bool dfs(TreeNode *cur, TreeNode *minNode, TreeNode *maxNode)
    {
        if (!cur) return true;
        if (minNode && minNode->val >= cur->val) return false;
        if (maxNode && maxNode->val <= cur->val) return false;        
        
        return dfs(cur->left, minNode, cur) && dfs(cur->right, cur, maxNode);
    }
};

