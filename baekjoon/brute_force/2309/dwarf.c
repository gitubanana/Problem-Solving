#include <stdio.h>

void	print_arr(int *arr, int size);
void	insertion_sort(int *arr, int size);
void	print_ans(int *arr, int size, int sum);

int	main(void)
{
	int	i;
	int	sum, arr[9];

	sum = 0;
	for (i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	print_ans(arr, 9, sum);
	return (0);
}

void	print_ans(int *arr, int size, int sum)
{
	int	i, j, flag;

	flag = 1;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (arr[i] + arr[j] == sum - 100)
			{
				arr[i] = arr[j] = flag = 0;
				break;
			}
		}
		if (!flag)
			break;
	}
	insertion_sort(arr, size);
	print_arr(arr, size);
}

void	insertion_sort(int *arr, int size)
{
	int	i, j, tmp;

	for (i = 1; i < size; i++)
	{
		tmp = arr[(j = i)];
		while (--j >= 0 && arr[j] > tmp)
		{
			arr[j + 1] = arr[j];
			arr[j] = tmp;
		}
	}
}

void	print_arr(int *arr, int size)
{
	int	i;

	for (i = 2; i < size; i++)
		printf("%d\n", arr[i]);
}
