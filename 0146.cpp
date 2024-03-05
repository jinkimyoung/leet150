#include <unordered_map>
using namespace std;
class Node {
public:
    int k, val;
    Node *prev, *next;
    Node(int key, int value) : k(key), val(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> cache;
    Node *left, *right;

    void remove(Node *node) {
        Node *prev = node->prev, *next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    void insert(Node *node)
    {
        Node *prev = right->prev, *next = right;
        prev->next = node;
        next->prev = node;
        node->prev = prev;                        
        node->next = next;
    }

    LRUCache(int capacity) {
        cap = capacity;

        left = new Node(0, 0);
        right = new Node(0, 0);     
        left->next = right;
        right->prev = left;
    }
   
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        remove(cache[key]);
        insert(cache[key]);
        return cache[key]->val;
    }
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            delete cache[key];
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);
        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->k);    // important
            delete lru;
        }        
    }
};