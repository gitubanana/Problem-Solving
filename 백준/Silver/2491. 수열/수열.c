#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100000

void	print_max_size(int *arr, int size, int dp[2][MAX])
{
	int	i;
	int	max_size[2];

	dp[0][0] = dp[1][0] = 1;
	for (i = 1; i < size; i++)
	{
		//커지는 수열일 때
		if (arr[i - 1] <= arr[i])
			dp[0][i] = dp[0][i - 1] + 1;
		else
			dp[0][i] = 1;
		//작아지는 수열일 때
		if (arr[i - 1] >= arr[i])
			dp[1][i] = dp[1][i - 1] + 1;
		else
			dp[1][i] = 1;
	}
	max_size[0] = max_size[1] = 0;
	for (i = 0; i < size; i++)
	{
		//커지는 수열의 최댓값
		if (max_size[0] < dp[0][i])
			max_size[0] = dp[0][i];
		//작아지는 수열의 최댓값
		if (max_size[1] < dp[1][i])
			max_size[1] = dp[1][i];
	}
	printf("%d", max_size[0] > max_size[1] ? max_size[0] : max_size[1]);
}

int	main(void)
{
	int	i;
	int	*arr, size;
	int	dp[2][MAX];

	scanf("%d", &size);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (perror(""), 1); //perror의 반환값이 void기 때문에 가능하다.
	for (i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	print_max_size(arr, size, dp);
	return (0);
}