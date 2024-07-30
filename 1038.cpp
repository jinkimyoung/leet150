 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#include <stack>
using namespace std;

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return nullptr;

        stack<TreeNode*> stk;
        TreeNode *node = root;
        int sum = 0;
        while (node || !stk.empty())
        {
            while (node)
            {
                stk.push(node);
                node = node->right;
            }

            node = stk.top();
            stk.pop();
            sum += node->val;
            node->val = sum;

            node = node->left;
        }
        return root;
    }
};