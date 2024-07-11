struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
  
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<pair<TreeNode*, int>> q;
        map<int, vector<int>> mp;
        q.push({root, 0});

        while (!q.empty())
        {
            for (int i = q.size(); i > 0; i--)
            {
                TreeNode *node = q.front().first;
                int col = q.front().second;
                q.pop();

                mp[col].push_back(node->val);
                if (node->left) q.push({node->left, col-1});
                if (node->right) q.push({node->right, col+1});
            }
        }

        for (auto e : mp)   
            ans.push_back(e.second);
        return ans;      
    }
};