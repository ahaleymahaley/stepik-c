#define AAA
#ifdef AAA
#include <stdio.h>
void simpleFactors(unsigned int a, unsigned int last, unsigned int n);
void printFactor(unsigned int last, unsigned int n);

int main()
{
	unsigned int a;
	scanf("%u", &a);
	simpleFactors(a, 2, 0);
	return 0;
}
#endif

void simpleFactors(unsigned int a, unsigned int last, unsigned int n)
{
	if (a < last)
	{
		if (n > 0)
		{
			printFactor(last, n);
		}
	}
	else if (a % last == 0)
	{
		simpleFactors(a / last, last, n + 1);
	}
	else
	{
		simpleFactors(a, last + 1, 0);
		if (n > 0)
		{
			printFactor(last, n);
		}
	}
}
void printFactor(unsigned int last, unsigned int n)
{
	if (n > 1)
	{
		printf("%u^%u ", last, n);
	}
	else
	{
		printf("%u ", last);
	}
}
