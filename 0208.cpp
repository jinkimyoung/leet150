
#include <string>
using namespace std;
class TrieNode {
public:
    TrieNode    *node[26];
    bool isWord;
    TrieNode() {
        for (int i = 0; i < 26; i++)
            node[i] = NULL;
        isWord = false;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() { root = new TrieNode(); }

    ~Trie() { }

    void insert(string word) {
        TrieNode *e = root;        
        for (char c : word)
        {
            if (!e->node[c - 'a'])  e->node[c - 'a'] = new TrieNode();
            e = e->node[c - 'a'];
        }
        e->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *e = root;        
        for (char c : word)
        {
            if (!e->node[c - 'a'])  return false;
            e = e->node[c - 'a'];
        }
        return e->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *e = root;        
        for (char c : prefix)
        {
            if (!e->node[c - 'a'])  return false;
            e = e->node[c - 'a'];
        }
        for (int i = 0; i < 26; i++)
            if (e->node[i]) return true;
        return e->isWord; 
    }
};
