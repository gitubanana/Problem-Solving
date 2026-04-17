#include <list>
#include <cstring>
#include <iostream>

const int	MAX = 1000;

std::list<int>	dp_arr[MAX];

void	print_long_big(int *&arr, int &size)
{
	int	i, j, max_idx;
	int	*dp = new int[size];

	for (i = 0; i < size; i++)
		dp[i] = 1;
	for (i = 1; i < size; i++)
		for (j = i - 1; j >= 0; j--)
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1, dp_arr[i] = dp_arr[j], dp_arr[i].push_back(j);

	/* 최대 길이 출력 */
	max_idx = 0;
	for (i = 1; i < size; i++)
		if (dp[max_idx] < dp[i])
			max_idx = i;
	std::cout << dp[max_idx] << std::endl;
	
	/* 가장 긴 증가하는 부분 수열 출력 */
	while (!dp_arr[max_idx].empty())
	{
		std::cout << arr[dp_arr[max_idx].front()] << " ";
		dp_arr[max_idx].pop_front();
	}
	std::cout << arr[max_idx];
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
	print_long_big(arr, size);
	delete[] arr;
	return (0);
}