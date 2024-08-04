
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root)  return NULL;
        if (root->val == p->val || root->val == q->val) return root;
        
        TreeNode *left, *right;
        left = lowestCommonAncestor(root->left, p, q);
        right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right)  return root;
        else if (left) return left;
        else if (right) return right;
        
        return NULL;
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root) return nullptr;
        
        return dfs(root, p, q);
    }
    
    TreeNode* dfs(TreeNode *n, TreeNode *p, TreeNode *q)
    {
        if (!n) return nullptr;
        else if (n == p || n == q) return n;
        
        TreeNode *l = dfs(n->left, p, q);
        TreeNode *r = dfs(n->right, p, q);        
        if (l && r) return n;
        else if (l) return l;
        else if (r) return r;

        return nullptr;
    }
};
