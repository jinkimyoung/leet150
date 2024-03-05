
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, root->val, ans);
        return ans;
    }

    void dfs(TreeNode *root, int maxSoFar, int &ans)
    {
        if (!root)  return;
        if (root->val >= maxSoFar)  ans++;

        dfs(root->left, max(root->val, maxSoFar), ans);
        dfs(root->right, max(root->val, maxSoFar), ans);        
    }
};
