
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root)  return -1;
        stack<TreeNode *> stk;
        TreeNode *node = root;
        while (true)
        {
            while (node)
            {
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            k--;
            if (k == 0) return node->val;
            
            node = node->right;
        }
        return -1;
    }
};