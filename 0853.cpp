
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(), ans = 0;
        vector<pair<int, double>> cars; // (position : time)
        double time = 0.0, maxTime = 0.0;

        for (int i = 0; i < n; i++)
        {
            time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        // 10, 9, 8
        sort(cars.begin(), cars.end(), [](auto &a, auto &b) { return a.first > b.first; });
        for (int i = 0; i < n; i++)
        {
            if (maxTime < cars[i].second)
            {
                maxTime = cars[i].second;
                ans++;
            }
        }
        return ans;
    }
};

int main(void)
{
    vector<int> position = { 8,12,16,11,7 } ;
    vector<int> speed = { 6,9,10,9,7 } ;

    vector<pair<int, double>> cars; // (position : speed)
    int target = 17;

    for (int i = 0; i < position.size(); i++)
    {
        double time = (double)(target - position[i]) / speed[i];
        cars.push_back({position[i], time});
    }
    sort(cars.begin(), cars.end(), [](auto &a, auto &b) { return a.first > b.first; });
    
    for (int i = 0; i < position.size(); i++)
        cout << cars[i].first << " : " << cars[i].second << endl;
    return 0;
}