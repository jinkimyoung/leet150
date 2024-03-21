

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;
        for (int weight : stones)
            pq.push(weight);
        
        while (pq.size() > 1)
        {
                int n1, n2;
                n1 = pq.top();
                pq.pop();
                n2 = pq.top();
                pq.pop();
                if (n1 != n2)   pq.push(n1-n2);
        }
        return pq.size() == 0 ? 0 : pq.top();
    }
};