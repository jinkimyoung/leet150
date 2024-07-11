#include <vector>
#include <unordered_map>
using namespace std;

class DisjointSet {
public:
    vector<int> ranks, parents;
    DisjointSet(int n) { 
        ranks.resize(n+1, 0);
        parents.resize(n+1);
        for (int i = 0; i <= n; i++) 
            parents[i] = i;
    }
    
    int findParent(int n)
    {
        int p = parents[n];
        while (p != parents[p])
        {
            parents[p] = parents[parents[p]];
            p = parents[p];
        }
        return p;
    }

    void doUnion(int n1, int n2)
    {
        int p1 = findParent(n1), p2 = findParent(n2);
        if (p1 == p2) return ;
        if (ranks[p1] > ranks[p2])
        {
            parents[p2] = p1;
            ranks[p1] += ranks[p2];
        }
        else
        {
            parents[p1] = p2;
            ranks[p2] += ranks[p1];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int m = accounts.size();
        DisjointSet ds(m);
        unordered_map<string, int> mp;

        for (int i = 0; i < m; i++)
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mp.find(mail) == mp.end())
                    mp[mail] = i;
                else
                    ds.doUnion(mp[mail], i);
            }

        vector<string> users[m];
        for (auto it : mp)
        {
            string mail = it.first;
            int node = ds.findParent(it.second);
            users[node].push_back(mail);
        }

        vector<vector<string>> flist;
        for (int i = 0; i < m; i++)
        {
            if (users[i].size() == 0) continue;
            sort(users[i].begin(), users[i].end());

            vector<string> merge;
            merge.push_back(accounts[i][0]);    // name
            for (auto mail : users[i])
                merge.push_back(mail);
            flist.push_back(merge);
        }
        return flist;
    }
};