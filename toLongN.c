#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 200

typedef struct {
	char *dig;
	int n;
	char sign;
} LongN;

void destroy_LongN(LongN l) {
	free(l.dig);
}

LongN getLongN(char *s) {
	LongN l;
	l.sign = s[0] == '-';
	int is_signed = s[0] == '-' || s[0] == '+';
	l.n = (strlen(s) - is_signed) / 2 + (strlen(s) - is_signed) % 2;
	l.dig = malloc(l.n);
	int i, j;
	for (i = strlen(s) - 1, j = 0; i >= is_signed; i -= 2, j++) {
		l.dig[j] = s[i] - '0';
 		if (i - 1 >= is_signed)	
			l.dig[j] += (s[i - 1] - '0') * 10;
	}
	return l;
}

void printLongN(LongN l) {
	int i;
	printf("%c ", l.sign ? '-' : '+');
	for (i = 0; i < l.n; i++)
       		printf("%hhd ", l.dig[i]);
	printf("\n");
}

int main() {
	char s[N];
	scanf("%s", s);
	LongN x = getLongN(s);
	printLongN(x);
	destroy_LongN(x);
	return 0;
}
