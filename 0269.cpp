#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> graph;
        queue<char> q;
        string ans;

        // initialization
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words[i].size(); j++)
                indegree[words[i][j]] = 0;

        // build graph/indegree
        for (int i = 0; i < words.size() - 1; i++)
        {
            string cur = words[i], nex = words[i+1];
            if (cur.length() > nex.length() && cur.compare(0, nex.length(), nex) == 0)
                return "";

            int mlen = min(cur.length(), nex.length());
            for (int j = 0; j < mlen; j++)
            {
                if (cur[j] != nex[j])
                {
                    if (graph[cur[j]].find(nex[j]) == graph[cur[j]].end())
                    {
                        graph[cur[j]].insert(nex[j]);
                        indegree[nex[j]]++;
                    }
                    break;
                }
            }
        }

        // Topological sort
        for (auto e : indegree)
            if (e.second == 0)
                q.push(e.first);
                
        while (!q.empty())
        {
            char c = q.front();
            q.pop();
            ans.push_back(c);

            for (auto e : graph[c])
            {
                indegree[e]--;
                if (indegree[e] == 0)
                    q.push(e);
            }
        }
         // tell if it is cyclic
        return ans.length() == indegree.size() ? ans : "";
    }
};
