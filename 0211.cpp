
#include <string>
using namespace std;

class Trie {
public:
    Trie    *child[26];
    bool    isWord;
    Trie() {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        isWord = false; 
    }
};

class WordDictionary {
public:
    Trie *root;

    WordDictionary()
    {
        root = new Trie();
    }

    void addWord(string word) {
        Trie *node = root;
        for (char c : word)
        {
            if (!node->child[c-'a'])    node->child[c-'a'] = new Trie();
            node = node->child[c-'a'];
        }
        node->isWord = true;
    }
    
    bool search(string word) 
    {
        return searchIdx(word, 0, word.length(), root);     
    }

    bool searchIdx(string word, int idx, int len, Trie *node) 
    {
        if (idx == len)   return node->isWord;
        char c = word[idx];
        if (c == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->child[i])
                    if (searchIdx(word, idx+1, len, node->child[i]))   return true;
            }
            return false;
        }
        else
        {
            if (!node->child[c-'a'])    return false;
            if (!searchIdx(word, idx+1, len, node->child[c-'a']))   return false;
        }
        return true;
    }    
};
