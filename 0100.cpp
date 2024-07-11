#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)   return true;
        else if (!p)    return false;
        else if (!q)    return false;
        if (p->val != q->val)   return false;

        if (!isSameTree(p->left, q->left) || !isSameTree(p->right, q->right))
            return false;

        return true;
    }
};
