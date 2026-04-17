#include <iostream>
#include <algorithm>

const int	MAX = 10001;

int	arr[MAX];
int	dp[MAX];

void	make_dp(int &size)
{
	int		i;

	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (i = 3; i <= size; ++i)
		dp[i] = std::max({dp[i - 1], dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]});
	printf("%d\n", dp[size]);
}

int	main(void)
{
	int	i, size;

	scanf(" %d", &size);
	for (i = 1; i <= size; ++i)
		scanf(" %d", &arr[i]);
	make_dp(size);
	return (0);
}
