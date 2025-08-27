#include <stdio.h>
#include <ctype.h>
#define DIGIT(x) (x) - '0'
int main() {
	char d; 
	int i = 0;
	scanf("%hhd", &d);
	printf("%hhd ", d);
	int c;
	do {
		c = getchar();

		if (isdigit(c))
			printf("%c", c);
			
		if (DIGIT(c) == d) 
			i++;
	} while (c != EOF); 
	printf(" %d\n", i);
	return 0;
}
