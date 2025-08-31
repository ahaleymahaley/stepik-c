#include <stdio.h>
#define N 100
typedef struct {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
}Decimal;

void elong_print(Decimal x) {
        int i;
        for (i = x.n; i >= 0; i--) {
                printf("%hhd", x.a[i]);
        }
        printf("\n");
}

void elong_set(Decimal *res, const char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    res->n = i - 1;
    for (i = res->n; i >= 0; i--) {
        res->a[i] = str[res->n - i] - '0';
    }
}

int main() {
	Decimal res;
	elong_set(&res, "123456");
	elong_print(res);
	return 0;
}
