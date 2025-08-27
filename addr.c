#include <stdio.h>


int main()
{
    int x = 123;
    int * p = &x;
    int ** pp = &p;


    printf("x = %d\n", x);
    printf("p = %p\n", p);
    printf("pp = %p\n", pp);
    printf("%zu\n", sizeof x);
    printf("%zu\n", sizeof(1 + 2));
    printf("%zu\n", sizeof 3.5);
    printf("%zu\n", sizeof(char));
    printf("%zu\n", sizeof(char*));
    printf("%zu\n", sizeof(double*));
    printf("%zu\n", sizeof(int*));
    printf("%zu\n", sizeof(void*));
    printf("%zu\n", sizeof(int**));
    printf("%zu\n", sizeof(int***));
    return 0;
}

