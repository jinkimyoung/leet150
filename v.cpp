#include <stdio.h>

#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<int> a = { 5, 20, 10, 7};
    sort(a.begin(), a.end());
    for (int n : a)
        printf("%d\n", n);

    return 0;
}