#include <string>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for (int i = 0; i < wordList.size(); i++)
            dict.insert(wordList[i]);
        
        queue<string> q;
        q.push(beginWord);
        
        int result = 1;
        
        while (!q.empty()) {
            int count = q.size();
            
            for (int i = 0; i < count; i++) {
                string word = q.front();
                q.pop();
                
                if (word == endWord)    return result;
                dict.erase(word);
                
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = k + 'a';
                        if (dict.find(word) != dict.end()) {
                            q.push(word);
                            dict.erase(word);
                        }
                        word[j] = c;
                    }
                }
            }
            result++;
        }
        return 0;
    }
};

#include <set>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int trans = 0;
        queue<string> q;
        set<string> st;
        
        for (string w : wordList)
            st.insert(w);

        q.push(beginWord);
        while (!q.empty())
        {
            trans++;
            for (int i = q.size(); i > 0; i--)
            {
                string word = q.front();
                q.pop();
             
                if (endWord == word) return trans;
                
                for (int j = 0; j < word.length(); j++)
                {
                    char c = word[j];
                    for(int k = 0; k < 26; k++)
                    {
                        word[j] = k + 'a';
                        if (st.find(word) != st.end())
                        {
                            st.erase(word);
                            q.push(word);
                        }
                    }
                    word[j] = c;
                }
            }
        }        
        return 0;
    }
};
