

#include <vector>
#include <string>
using namespace std;

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> svecs;
        
        dfs(root, svecs, "");
        return svecs;
    }
    
    void dfs(TreeNode *node, vector<string> &routes, string s)
    {
        if (!node)  return ;

        string itinerary = s + to_string(node->val);
        if (!node->left && !node->right)
            routes.push_back(itinerary);

        itinerary += "->";
        dfs(node->left, routes, itinerary);
        dfs(node->right, routes, itinerary);
    }
};

