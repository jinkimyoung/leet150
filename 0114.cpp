

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

class Solution {
public:
    void flatten(TreeNode* root) {

        if (!root) return;
    
        TreeNode *node = root;
        while (node)
        {
            // If the node has a left child
            if (node->left)
            {
                TreeNode *rightmost = node->left;
                while (rightmost->right)
                    rightmost = rightmost->right;

                // rewire the connections
                rightmost->right = node->right;
                node->right = node->left;
                node->left = nullptr;
            }
            // move on to the right side of the tree
            node = node->right;
        }
    }
};

