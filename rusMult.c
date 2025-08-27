#include <stdio.h>

int rusMult(int a, int b);

int main() 
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", rusMult(a, b));
	return 0;
}

int rusMult(int a, int b)
{
	int res = 0;
	printf("%d %d\n", a, b);
	if (b > 1)
	{
		res = rusMult(a * 2, b / 2);
		printf("%d %d %d ", res, a, b % 2);
	}
	if (b % 2 == 1)
	{
		res += a;
	}
	printf("%d\n", res);
	return res;
}
