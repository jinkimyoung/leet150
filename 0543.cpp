
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;        
    }

    int dfs(TreeNode *node, int &ans)
    {
        if (!node)  return 0;
        int left = dfs(node->left, ans);
        int right = dfs(node->right, ans);
        ans = max(ans, left+right);
        return 1 + max(left, right);
    }
};