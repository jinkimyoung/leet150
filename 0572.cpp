
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot)  return true;
        else if (!root || !subRoot) return false;

        if (isSame(root, subRoot))  return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSame(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)   return true;
        else if (!p || !q)    return false;

        if (p->val != q->val)   return false;
        return isSame(p->left, q->left) && isSame(p->right, q->right); 
    }
};