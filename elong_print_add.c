#include <stdio.h>
#define N 100

typedef struct {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
}Decimal;

void elong_print(Decimal x) {
	int i;
	printf("%d: ", x.n);
	for (i = x.n; i >= 0; i--) {
		printf("%d", x.a[i]);
	}
	printf("\n");
}

Decimal add(Decimal x, Decimal y) {
	Decimal res;
	int n;
	Decimal *px, *py;
	if (x.n > y.n) {
		n = x.n;
		px = &x;
		py = &y;
	} else {
		n = y.n;
		px = &y;
		py = &x;
	}
	char i, extra = 0;
	for (i = 0; i <= n; i++) {
		if (i <= py->n) {
			res.a[i] = (extra + px->a[i] + py->a[i]) % 10;
			extra = (extra + px->a[i] + py->a[i]) / 10; 
		} else {
			res.a[i] = (extra + px->a[i]) % 10;
			extra = (extra + px->a[i]) / 10;
		}
	}
	if (extra > 0) {
		n++;
		res.a[i] = 1;
	}
	res.n = n;
	return res;
}

int main()
{
    Decimal x = {{7, 4, 1}, 2}; 
    Decimal y ={{3, 1}, 1}; 
    Decimal res = add(x, y);
    elong_print(x);     
    elong_print(y);  
    elong_print(res);  

    return 0;
}
