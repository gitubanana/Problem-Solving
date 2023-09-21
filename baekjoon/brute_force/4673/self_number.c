#include <stdio.h>

int	d(int n);

int	main(void)
{
	int	i, tmp;
	int	check[10000] = {0, };

	for (i = 1; i < 10000; i++)
	{
		tmp = d(i);
		if (tmp <= 10000)
			check[tmp] = 1;
	}

	for (i = 1; i < 10000; i++)
		if (check[i] != 1)
			printf("%d\n", i);
}

int	d(int n)
{
	int	sum;

	sum = n;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return (sum);
}
