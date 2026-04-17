#include <stdio.h>

void	print_cnt(int n)
{
	int	i, dp[2][41];

	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	for (i = 2; i <= n; i++)
		dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
	for (i = 2; i <= n; i++)
		dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
	printf("%d %d\n", dp[0][n], dp[1][n]);
}


int	main(void)
{
	int	t, n;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		print_cnt(n);
	}
}