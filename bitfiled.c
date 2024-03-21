#include <stdio.h>
#include <stdlib.h>

struct bitfield {
    unsigned char a : 4;
    unsigned char   : 2;
    unsigned char b : 1;
    unsigned char   : 1;    
};

struct regA {
    unsigned int a : 4;
    unsigned int b : 10;
    unsigned int : 17;
    unsigned int c : 1;
};

int main(void)
{
    struct bitfield s;
    s.a = 0x7;
    s.b = 0x1;


    struct regA a;
    a.a = 0x4;
    a.b = 0xFF;

    *((unsigned int*)(&a)) = 0x1FF4;
    printf("0x%lp\n", *((unsigned int*)&a));
    printf("0x%lp\n", *((char*)&a));

    return 0;
}

int multiply(int n, int m)
{
    int result = 0;
    while (m)
    {
        if (m & 0x1)
            result = result + n;
        m = m >> 1; 
        n = n << 1;
    }
    return result;
}

