#include <stdio.h>
#include <stdint.h>

int main(void)
{
	int			n;
	int			test_cnt;
	uint64_t	dp[68];	

	dp[0] = dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 68; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	scanf("%d", &test_cnt);
	while (test_cnt--)
	{
		scanf("%d", &n);
		printf("%llu\n", dp[n]);
	}
	return (0);
}