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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
            
            if (ans.size() % 2)
                reverse(siblings.begin(), siblings.end());
            ans.push_back(siblings);
        }
        return ans;        
    }
};

