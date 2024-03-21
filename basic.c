

#include <stdio.h>

#define SIZEOF(X)   (sizeof(X)/sizeof(*X))
#define SIZEOF(object) (char *)(&object+1) - (char *)(&object)


int main(void)
{
    int i;
    struct tsp {
    int x;
    char y;
    short z;
    } __attribute__((packed)) asp[] = {
    {0,0,0},
    {1,1,1},
    {2,2,2}
    };
    struct tsp *psp = asp;
    struct tsp *old_psp;
    for (i = 0; i < SIZEOF(asp); i++) {
    old_psp = psp++;
    printf("Address of ps: %p, element spacing: %ld, address spacing: %ld\n", old_psp, (size_t)(psp - old_psp), (size_t)psp - (size_t)old_psp);
    }

    return 0;
}


