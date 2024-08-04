#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int  m = version1.length(), n = version2.length();
        int i = 0, j = 0;
        while (i < m || j < n)
        {
            int v1 = 0, v2 = 0;
            while (i < m)
            {
                char c = version1[i++];
                if (c != '.')   v1 = v1 * 10 + (c - '0');
                else break;
            }

            while (j < n)
            {
                char c = version2[j++];
                if (c != '.')   v2 = v2 * 10 + (c - '0');
                else break;
            }

            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;
        }
        return 0;
    }
};