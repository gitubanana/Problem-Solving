#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 1000

int	get_max_subarray(int *arr, int size, int *dp)
{
	int	i, max;

	dp[0] = arr[0];
	for (i = 1; i < size; i++)
	{
		if (dp[i - 1] + arr[i] > arr[i])
			dp[i] = dp[i - 1] + arr[i];
		else
			dp[i] = arr[i];
	}
	max = INT_MIN;
	for (i = 0; i < size; i++)
	{
		if (max < dp[i])
			max = dp[i];
	}
	return (max);
}

int	main(void)
{
	int	i, test_cnt;
	int	*arr, size;
	int	dp[MAX];

	scanf("%d", &test_cnt);
	while (test_cnt--)
	{
		scanf("%d", &size);
		arr = malloc(sizeof(int) * size);
		for (i = 0; i < size; i++)
			scanf("%d", &arr[i]);
		printf("%d\n", get_max_subarray(arr, size, dp));
		free(arr);
	}	
	return (0);
}