#include <stdio.h>

long long int ipow(long long int a, unsigned int n, unsigned int * depth)
{
    long long int res;
    if (n == 0)
    {
	*depth = 1;
	res = 1;
    }
    else if (n == 1) 
    {
	*depth = 1;
        res = a;
    }
    else if (n % 2 == 0) 
    { 
        res = ipow(a, n / 2, depth);
	res *= res;
	(*depth)++;    
    }
    else 
    {
	res = a * ipow(a, n - 1, depth);
	(*depth)++;
    }
    printf("n:%u depth:%u\n", n, *depth);
    return res;
}

int main()
{
	long long int a, res;
	unsigned int n, depth;
	scanf("%lld%u", &a, &n);
	res = ipow(a, n, &depth);
	printf("%lld %u\n", res, depth);
	return 0;
}
