
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->val < p->val && cur->val < q->val )    
                cur = cur->right;
            else if (p->val < cur->val && q->val < cur->val)    
                cur = cur->left;
            else 
                return cur;    
        }
        return cur;
    }
};