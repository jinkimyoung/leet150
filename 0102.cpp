
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)  return ans;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> l;
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);                

                l.push_back(node->val);
            }
            ans.push_back(l);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> siblings;
            for (int i = q.size(); i > 0; i--)
            {
                TreeNode *n = q.front();
                q.pop();
                siblings.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            ans.push_back(siblings);
        }
        return ans;
    }
};

