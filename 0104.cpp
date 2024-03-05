
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int ans = 0;

        if (!root)  return 0;
        q.push(root);
        while (!q.empty())
        {
            for (int i = 0, count = q.size(); i < count; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans++;
        }
        return ans;
    }
};