#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool>    inMST(n, false);
        vector<int>     minDist(n, INT_MAX);
        minDist[0] = 0;

        int usedEdges = 0, ans = 0;
        while (usedEdges < n)
        {
            int curMinEdge = INT_MAX, curNode = -1;
            // greadily pick lowest cost node not in MST
            for (int i = 0; i < n; i++)
            {
                if (!inMST[i] && curMinEdge > minDist[i])
                {
                    curNode = i;
                    curMinEdge = minDist[i];
                }
            }
            
            ans += curMinEdge;
            inMST[curNode] = true;
            usedEdges++;

            // update adj nodes of cur node
            for (int i = 0; i < n; i++)
            {
                int cost = abs(points[curNode][0] - points[i][0]);
                cost += abs(points[curNode][1] - points[i][1]);
                if (!inMST[i] && minDist[i] > cost)
                    minDist[i] = cost;
            } 
        }
        return ans;
    }
};