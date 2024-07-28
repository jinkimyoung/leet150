

#include <priority_queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Sort intervals based on the start value
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        // Prepare to handle queries
        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());
        map<int, int> res;

        // Priority queue to store intervals, sorted by their size then end point
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);

        int i = 0;
        for (int q : sortedQueries) {
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                minHeap.push({r - l + 1, r});
                i++;
            }

            while (!minHeap.empty() && minHeap.top()[1] < q) {
                minHeap.pop();
            }

            res[q] = minHeap.empty() ? -1 : minHeap.top()[0];
        }

        // Build the result vector from the map
        vector<int> result(queries.size());
        for (int j = 0; j < queries.size(); j++) 
            result[j] = res[queries[j]];
        
        return result;
    }
};