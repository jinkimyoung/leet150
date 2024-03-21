#include <string>

#define CLR(N, K)	(N & ~(1<<K))
#define SET(N, K)	(N | (1<<K))
#define TEST(N, K) ((N & (1<<K)) != 0)
#define TGL(N,K) (N ^ (1 << K))


void swap(int a, int b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

int toggleBits(int num, int i, int j)
{
    // i and j's range : 0-31
    int mask = (1 << (j - i + 1)) - 1;
    mask <<= i;
    return (num ^ mask);
}

//  Function to check if x is power of 2
bool isPowerOfTwo(int x)
{
     // First x in the below expression is
     // for  the case when x is 0 
     return x && (!(x & (x - 1)));
}

 static int toggleBit(int number, int index) {
    int mask = 1 << index;
    return number ^ mask;
}

int add_one_to_int()
{
    int x = 4;
    cout << x << " + " << 1 << " is " << -~x << endl;
 
    x = -5;
    cout << x << " + " << 1 << " is " << -~x << endl;
 
    x = 0;
    cout << x << " + " << 1 << " is " << -~x << endl;
 
    return 0;
}

// Function to turn off k'th bit in `n`
int turnOffKthBit(int n, int k) {
    return n & ~(1 << k);
}

int turnOnKthBit(int n, int k) {
    return n | (1 << k);
}

bool isKthBitSet(int n, int k) {
    return (n & (1 << k)) != 0;
}

int toggleKthBit(int n, int k) {
    return n ^ (1 << k);
}

bool isPowerOfTwo(unsigned n)
{
	cout << n << " in binary is " << bitset<8>(n) << "\n";
	cout << n - 1 << " in binary is " << bitset<8>(n-1) << "\n\n";

	return !(n & (n - 1));
}

// Returns the position of the rightmost set bit of `n`
int positionOfRightmostSetBit(int n)
{
    // if the number is odd, return 1
    if (n & 1) {
        return 1;
    }
 
    // unset rightmost bit and xor with the number itself
    n = n ^ (n & (n - 1));
 
    int pos = 0;
    while (n)
    {
        n = n >> 1;
        pos++;
    }
    return pos;
}

void convert_alphabets(void)
{
    // Convert lowercase alphabet to uppercase
    for (char ch = 'a'; ch <= 'z'; ch++) {
        cout << char(ch ^ ' '));        // prints ABCDEFGHIJKLMNOPQRSTUVWXYZ
    }
    
    // Convert uppercase alphabet to lowercase
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        cout << char(ch ^ ' '));        // prints abcdefghijklmnopqrstuvwxyz
    }
}


string convertToBase7(int num) {
    if (num < 0)
        return "-" + convertToBase7(-num);
    if (num < 7)
        return to_string(num);
    return convertToBase7(num / 7) + to_string(num % 7);
    }
;

#include <bit>
#include <cstdint>
#include <iostream>
 
struct S
{
    // will usually occupy 2 bytes:
    unsigned char b1 : 3; // 1st 3 bits (in 1st byte) are b1
    unsigned char    : 2; // next 2 bits (in 1st byte) are blocked out as unused
    unsigned char b2 : 6; // 6 bits for b2 - doesn't fit into the 1st byte => starts a 2nd
    unsigned char b3 : 2; // 2 bits for b3 - next (and final) bits in the 2nd byte
};
 
int main()
{
    std::cout << sizeof(S) << '\n'; // usually prints 2
 
    S s;
    // set distinguishable field values
    s.b1 = 0b111;
    s.b2 = 0b101111;
    s.b3 = 0b11;
 
    // show layout of fields in S
    auto i = std::bit_cast<std::uint16_t>(s);
    // usually prints 1110000011110111
    // breakdown is:  \_/\/\_/\____/\/
    //                 b1 u a   b2  b3
    // where "u" marks the unused :2 specified in the struct, and
    // "a" marks compiler-added padding to byte-align the next field.
    // Byte-alignment is happening because b2's type is declared unsigned char;
    // if b2 were declared uint16_t there would be no "a", b2 would abut "u".
    for (auto b = i; b; b >>= 1) // print LSB-first
        std::cout << (b & 1);
    std::cout << '\n';
}

// Output
//    2
// 1110000011110111


/*

int main(void)
{
    for (int i = 0; i <= 16; i++)
        std::cout << i << " : " << turnOffKthBit(0xFFFF, i) << endl;          
}

*/

#