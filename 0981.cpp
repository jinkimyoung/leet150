
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> m;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) return "";
        int low = 0, high = m[key].size() - 1, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (m[key][mid].first < timestamp)      low = mid + 1;
            else if (m[key][mid].first > timestamp) high = mid - 1;
            else return m[key][mid].second;
        }
        if (high >= 0)  return m[key][high].second;
        return "";
    }
};

