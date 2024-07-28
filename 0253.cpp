

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start, end;
        int max_room = INT_MIN, num_room = 0;

        for (auto itv : intervals)
        {
            start.push_back(itv[0]);
            end.push_back(itv[1]);            
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());        

        int s = 0, e = 0, n = intervals.size();
        while (s < n)
        {
            if (start[s] < end[e])
            {
                num_room++;
                max_room = max(max_room, num_room);                
                s++;
            }
            else
            {
                num_room--;
                e++;
            }
        }
        return max_room;
    }
};

