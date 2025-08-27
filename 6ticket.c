#include <stdio.h>

void print_revers(int x);

int main()
{
	int x;
	scanf("%d", &x);
	print_revers(x);
	return 0;
}

void print_revers(int x)
{
	printf("%d", x % 10);
	x /= 10;
	printf("%d", x % 10);
	x /= 10;
	printf("%d", x % 10);
	x /= 10;
	printf("%d", x % 10);
	x /= 10;
	printf("%d", x % 10);
	x /= 10;
	printf("%d", x % 10);
}
