#include <iostream>

void	print_small_long(int *&arr, int &size)
{
	int	i, j, max_len;
	int	*dp = new int[size];

	for (i = 0; i < size; i++)
		dp[i] = 1;
	for (i = 1; i < size; i++)
		for (j = i - 1; j >= 0; j--)
			if (arr[j] < arr[i])
				dp[i] = std::max(dp[i], dp[j] + 1);
	max_len = dp[0];
	for (i = 1; i < size; i++)
		if (max_len < dp[i])
			max_len = dp[i];
	std::cout << max_len;
	delete[] dp;
}

int	main(void)
{
	int	i;
	int	*arr, size;

	std::cin >> size;
	arr = new int[size];
	for (i = 0; i < size; i++)
		std::cin >> arr[i];
	print_small_long(arr, size);
	delete[] arr;
	return (0);
}