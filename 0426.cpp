
class Node {
public:
    int val;
    Node* left;
    Node* right;
};

class Solution {
public:
    Node *head = NULL, *tail = NULL;
   
    void dfs(Node *node)
    {
        if (!node) return ;
        dfs(node->left);
        
        if (!head) head = node;
        if (tail)
        {
            tail->right = node;
            node->left = tail;
        }
        tail = node;
        dfs(node->right);
    }
    
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        dfs(root);
        head->left = tail;
        tail->right = head;
        return head;
    }
};

