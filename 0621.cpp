

#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<vector<int>>  q;
        vector<int> counter(26);

        for (int i = 0; i < tasks.size(); i++)
            counter[tasks[i] - 'A']++;
        for (int i = 0; i < 26; i++)
            if (counter[i]) pq.push(counter[i]);
        
        int time = 0;
        while (!q.empty() || !pq.empty())
        {
            time++;
            if (!pq.empty())
            {
                if (pq.top() - 1)
                    q.push({pq.top() - 1, time + n});
                pq.pop();                    
            }
            if (!q.empty() && q.front()[1] == time) 
            {
                pq.push(q.front()[0]);
                q.pop();
            }
        }
        return time;        
    }
};