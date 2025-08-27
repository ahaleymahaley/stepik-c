#include <stdio.h>

float fahr(int cel) {
    float res;
    res = cel * 9 / 5 + 32;
    return res;
}

int main() {
    int cel;
    float f;
    scanf("%d", &cel);
    f = fahr(cel);
    printf("%f", f);
    return 0;
}