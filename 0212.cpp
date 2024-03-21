#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        isWord = false;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        TrieNode    *node, root;
        
        for (string w : words)
        {
            node = &root;
            for (int i = 0; i < w.length(); i++)
            {
                if (!node->child[w[i] - 'a'])   node->child[w[i] - 'a'] = new TrieNode();
                node = node->child[w[i] - 'a'];
            }
            node->isWord = true;
        }

        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                search(board, i, j, m, n, &root, "", ans);

        return ans;
    }

    void search(vector<vector<char>> &board, int i, int j, int m, int n, TrieNode *node, string word, vector<string>& ans)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (board[i][j] == '#') return ;
        char c = board[i][j];

        node = node->child[c-'a'];
        word += c;
        if (!node)  return ;
        if (node->isWord) {
            ans.push_back(word);
            node->isWord = false;
        }

        board[i][j] = '#';
        search(board, i+1, j, m, n, node, word, ans);
        search(board, i-1, j, m, n, node, word, ans);
        search(board, i, j+1, m, n, node, word, ans);
        search(board, i, j-1, m, n, node, word, ans);              
        board[i][j] = c;
    }
};