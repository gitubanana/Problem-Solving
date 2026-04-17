#include <iostream>

void	print_big_sum(int *&arr, int &size)
{
	int	i, j, max_sum;
	int	*dp = new int[size];

	for (i = 0; i < size; i++)
		dp[i] = arr[i];
	for (i = 1; i < size; i++)
		for (j = i - 1; j >= 0; j--)
			if (arr[j] < arr[i])
				dp[i] = std::max(dp[i], dp[j] + arr[i]);
	max_sum = dp[0];
	for (i = 1; i < size; i++)
		if (max_sum < dp[i])
			max_sum = dp[i];
	std::cout << max_sum;
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
	print_big_sum(arr, size);
	delete[] arr;
	return (0);
}