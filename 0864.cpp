
#include <vector>
#include <unordered_map>
#include <priority_queue>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> counts;
        priority_queue<int, vector<int>, greater<int>> minH;

        for (int card: hand)
            counts[card]++;
        
        for (auto e : counts)
            minH.push(e.first);

        while (!minH.empty())
        {
            int first = minH.top();
            for (int i = first; i < first + groupSize; i++)
            {
                if (counts.find(i) == counts.end())
                    return false;
                counts[i] -= 1;
                if (counts[i] == 0)
                {
                    if (i != minH.top())
                        return false;
                    minH.pop();
                }
            }
        }
        return true;
    }
};

