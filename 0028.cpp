
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.length(), n = haystack.length();
        if (n < m) return -1;

        vector<int> longest_border(m);
        int prev = 0, i = 1;

        while (i < m) {
            if (needle[i] == needle[prev]) {
                prev += 1;
                longest_border[i] = prev;
                i += 1;
            } else {
                if (prev == 0) {
                    longest_border[i] = 0;
                    i += 1;
                }
                else 
                    prev = longest_border[prev - 1];
            }
        }

        int haystackPointer = 0, needlePointer = 0;

        while (haystackPointer < n) {
            if (haystack[haystackPointer] == needle[needlePointer]) {
                needlePointer += 1;
                haystackPointer += 1;
                if (needlePointer == m)
                    return haystackPointer - m;
            } else {
                if (needlePointer == 0) 
                    haystackPointer += 1;
                else 
                    needlePointer = longest_border[needlePointer - 1];
            }
        }
        return -1;
    }
};