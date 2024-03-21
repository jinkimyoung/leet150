
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        queue<Node*>    q;

        if (!node)  return NULL;

        q.push(node);
        mp[node] = new Node(node->val);        
        while (!q.empty())
        {
            Node *cur = q.front();
            q.pop();

            for (int i = 0; i < cur->neighbors.size(); i++)
            {
                Node *neighbor = cur->neighbors[i];
                if (mp.find(neighbor) == mp.end())
                {
                    mp[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                mp[cur]->neighbors.push_back(mp[neighbor]);
            }
        }
        return mp[node];
    }
};