#include <stdio.h>

int rusDel(int a, int b)
{
	int res = 0, mult, rem;
	if (a % 2 == 0)
	{
		a /= 2;
		mult = 2;
		rem = 0;
	}
	else
	{
		a -= b;
		mult = 1;
		rem = 1;
	}
	if (a > 0)
	{
		printf("%d %d %d \n", a, mult, rem);
		res = rusDel(a, b);
	}
	else
	{
		printf("%d\n", 1);
		return 1;
	}
	printf("%d * %d + %d ", res, mult, rem);
	res = res * mult + rem;
	printf("= %d\n", res);
	return res;
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", rusDel(a, b));
	return 0;
}
