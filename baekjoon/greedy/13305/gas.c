#include <stdio.h>
#include <stdlib.h>

void	scan(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		scanf("%d", &arr[i++]);
}

void	print_ans(int *len, int size, int *cost)
{
	int			i;
	int			min;
	long long	sum;

	i = -1;
	sum = 0;
	min = cost[0];
	while (++i < size)
	{
		if (cost[i] < min)
			min = cost[i];
		sum += (long long)len[i] * (long long)min;
	}
	printf("%lld", sum);
}

int	main(void)
{
	int	n;
	int	*len;
	int	*cost;

	scanf("%d", &n);
	len = malloc(sizeof(int) * (n - 1));
	cost = malloc(sizeof(int) * n);
	if (!len || !cost)
		return (1);
	scan(len, n - 1);
	scan(cost, n);
	print_ans(len, n - 1, cost);
	free(len);
	free(cost);
	return (0);
}
