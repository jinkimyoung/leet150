

#include <vector>
#include <unordered_map>
using namespace std;

class DetectSquares {
public:
    unordered_map<long, int> ptsCount;
    vector<vector<int>> pts;

    long getKey(int x, int y) {
        return (static_cast<long>(x) << 32) | static_cast<long>(y);
    }

    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        long key = getKey(point[0], point[1]);
        ptsCount[key]++;
        pts.push_back(point);
    }
    
    int count(vector<int> point) {
        int res = 0;
        int px = point[0], py = point[1];   

        for (const auto& pt : pts) {
            int x = pt[0], y = pt[1];
            // Skip if it doesn't form a square side
            if (abs(py - y) != abs(px - x) || x == px || y == py) continue;

            // Check for other two corners of the square
            res += ptsCount[getKey(x, py)] * ptsCount[getKey(px, y)];
        }
        return res;             
    }
};
