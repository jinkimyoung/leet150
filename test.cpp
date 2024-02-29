

#include <iostream>
#include <bitset>
using namespace std;
 
// Find the total number of bits needed to be flipped to convert `x` to `y`
int findBits(int x, int y)
{
    // take XOR of `x` and `y` and store in `n`
    int n = x ^ y;
 
    // Using Brian Kernighan’s algorithm to count set bits
 
    // `count` stores the total bits set in `n`
    int count = 0;
 
    while (n)
    {
        n = n & (n - 1);    // clear the least significant bit set
        count++;
    }
 
    return count;
}
 
int main()
{
    int x = 65;
    int y = 80;
 
    std::cout << x << " in binary is " << bitset<8>(x) << endl;
    std::cout << y << " in binary is " << bitset<8>(y) << endl;
 
    std::cout << "\nThe total number of bits to be flipped is " << findBits(x, y);
 
    return 0;
}

// Compute a power of two less than or equal to `n`
unsigned findPreviousPowerOf2(unsigned n)
{
    // do till only one bit is left
    while (n & n - 1) {
        n = n & n - 1;        // unset rightmost bit
    }
 
    // `n` is now a power of two (less than or equal to `n`)
    return n;
}



// Using Brian Kernighan’s algorithm
int countSetBits(int n)
{
    int count = 0;

    while (n)
    {
        // clear the least significant bit set
        n = n & (n - 1);    
        count++;
    }
     return count;
}

// Function to find XOR of two numbers without using XOR operator
int findBits(int x, int y) {
    return (x | y) - (x & y);
}

// Returns true if adjacent bits are set in a binary representation of `n`
bool checkAdjacentBits(int n) {
    return n & (n << 1);
}
 
// Returns true if `n` is a power of four
bool checkPowerOf4(unsigned n)
{
    // return true if `n` is a power of 2, and
    // the remainder is 1 when divided by 3
    return !(n & (n - 1))&& (n % 3 == 1);
}

// Returns true if `n` is a power of 8
bool checkPowerOf8(unsigned n)
{
    // return true if `n` is a power of 2, and its only
    // set bit is present at (0, 3, 6, … ) position
    return n && !(n & (n - 1)) && !(n & 0xB6DB6DB6);
}
// Use mask 0xAAAAAAAA to check for power of 4
// Use mask 0xEEEEEEEE to check for power of 16

// Function to swap b–bits starting from position `p` and `q` in an integer `n`
int swap(int n, int p, int q, int b)
{
    // take XOR of bits to be swapped
    int x = ((n >> p) ^ (n >> q));
 
    // only consider the last b–bits of `x`
    x = x & ((1 << b) - 1);
 
    // replace the bits to be swapped with the XORed bits
    // and take its XOR with `n`
    return n ^ ((x << p) | (x << q));
}

 
// Function to perform left circular shift or right circular shift
// on integer `n` by `k` positions based on flag `isLeftShift`
int circularShift(unsigned n, int k, bool isLeftShift)
{
    // left shift by `k`
    if (isLeftShift) {
        return (n << k) | (n >> (32 - k));
    }
 
    // right shift by `k`
    return (n >> k) | (n << (32 - k));
}