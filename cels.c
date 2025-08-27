#include <stdio.h>
#include <assert.h>
#include <math.h>       
#define EPS 0.0001      

int eps(float a, float b)
{
    return fabs(a - b) < EPS;
}

float celsius(int fahr) {
    float res;
    res = 5.0 / 9.0 * (fahr - 32);
    return res;
}

int main() {
    int fahr;
    float cel;

    assert(eps(celsius(0), -17.777779));

    scanf("%d", &fahr);
    cel = celsius(fahr);
    printf("%f\n", cel);
    return 0;
}