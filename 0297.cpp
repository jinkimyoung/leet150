
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

#include <iostream>
using namespace std; 

class Codec {
public:
    void encode(ostringstream &o, TreeNode *node)
    {
        if (!node)
        {
            o << "N ";
            return ;
        }
        o << node->val << " ";
        encode(o, node->left);
        encode(o, node->right);
    }

    TreeNode* decode(istringstream &i)
    {
        string s;
        i >> s;
        if (s == "N") return NULL;
        
        TreeNode *node = new TreeNode(stoi(s));
        node->left = decode(i);
        node->right = decode(i);
        return node; 
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream o;
        encode(o, root);
        return o.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream i(data);
        return decode(i);
    }
};


