#include <stdio.h>

long long	gcd(long long a, long long b);

int	main(void)
{
	long long	a, b;
	long long	tmp;

	scanf("%lld %lld", &a, &b);
	tmp = gcd(a, b);
	for (int i = 0; i < tmp; i++)
		printf("1");
	return (0);
}

long long	gcd(long long a, long long b)
{
	while (a != 0 && b != 0)
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return (a + b);
}
