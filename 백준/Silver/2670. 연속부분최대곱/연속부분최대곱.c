#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	print_the_biggest(double *arr, int size, double *dp)
{
	int		i;
	double	max;

	dp[0] = arr[0];
	for (i = 1; i < size; i++)
	{
		if (dp[i - 1] * arr[i] > arr[i])
			dp[i] = dp[i - 1] * arr[i];
		else
			dp[i] = arr[i];
	}
	max = dp[0];
	for (i = 1; i < size; i++)
		if (max < dp[i])
			max = dp[i];
	printf("%.3lf", max);
}

int	main(void)
{
	int		size;
	double	*arr, *dp;

	scanf("%d", &size);
	dp = malloc(sizeof(double) * size);
	arr = malloc(sizeof(double) * size);
	if (!arr || !dp)
		return (free(dp), free(arr), perror(""), 1);
	for (int i = 0; i < size; i++)
		scanf("%lf", &arr[i]);
	print_the_biggest(arr, size, dp);
	return (free(dp), free(arr), 0);
}