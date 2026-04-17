#include <iostream>

void	print_arr(int *&arr, int &size)
{
	/* print_dp */
	std::cout << "=== start ===" << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::cout << "=== end ===" << std::endl;
	/* ========== */
}

void	print_long_bitonic(int *&arr, int &size)
{
	int	i, j, max_len;
	int	*dp_plus = new int[size];
	int	*dp_minus = new int[size];

	for (i = 0; i < size; i++)
		dp_plus[i] = 1, dp_minus[i] = 1;
	/* 증가하는 수열의 길이 구하기 */
	for (i = 1; i < size; i++)
		for (j = i - 1; j >= 0; j--)
			if (arr[j] < arr[i])
				dp_plus[i] = std::max(dp_plus[i], dp_plus[j] + 1);
	// std::cout << "** dp_plus **" << std::endl;
	// print_arr(dp_plus, size);
	/* 감소하는 수열의 길이 구하기 */
	for (i = size - 2; i >= 0; i--)
		for (j = i + 1; j < size; j++)
			if (arr[j] < arr[i])
				dp_minus[i] = std::max(dp_minus[i], dp_minus[j] + 1);
	// std::cout << "** dp_minus **" << std::endl;
	// print_arr(dp_minus, size);
	max_len = dp_plus[0] + dp_minus[0];
	for (i = 1; i < size; i++)
		if (max_len < dp_plus[i] + dp_minus[i])
			max_len = dp_plus[i] + dp_minus[i];
	std::cout << max_len - 1;
	delete[] dp_plus;
	delete[] dp_minus;
}

int	main(void)
{
	int	i;
	int	*arr, size;

	std::cin >> size;
	arr = new int[size];
	for (i = 0; i < size; i++)
		std::cin >> arr[i];
	print_long_bitonic(arr, size);
	delete[] arr;
	return (0);
}