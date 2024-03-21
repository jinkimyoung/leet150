
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int depth;

    KthLargest(int k, vector<int>& nums) {
        depth = k;
        for (int num : nums)
            minHeap.push(num);

        while (minHeap.size() > depth)
            minHeap.pop();
    }
    
    int add(int val) {
        minHeap.push(val);
        while (minHeap.size() > depth)
            minHeap.pop();

        return minHeap.top();
    }
};
