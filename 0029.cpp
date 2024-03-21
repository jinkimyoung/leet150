

// Time : O(logN)
#include <stdio.h>

int divide(int dividend, int divisor)
{
    int ans = 0;
    int k;
    
    while (dividend >= divisor)
    {
        k = 1;
        while (k * 2 * divisor <= dividend)
            k *= 2;        
        dividend -= k * divisor;
        ans += k;
    }
    return ans;
}

int main(void)
{
    printf("%d : %d -> %d\n", 1000, 3, divide(1000,3));
    return 0;
}