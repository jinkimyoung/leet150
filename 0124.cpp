
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;;
        dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode *node, int &ans)
    {
        if (!node)  return 0;
        int left = max(dfs(node->left, ans), 0);
        int right = max(dfs(node->right, ans), 0);

        ans = max(ans, node->val+(left + right));
        return max(left, right)+node->val;
    }
};