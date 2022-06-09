#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	n;
	int	size;
	int	*arr;

	scanf("%d", &n);
	size = get_size(n);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (1);
	with_sqaure(n, arr);
	print_ans(n, arr, size);
	return (0);
}

int	get_size(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	with_square(int n, int *arr)
{
	int	i;

	for (i = 1; i * i <= n; i++)
		arr[i - 1] = i * i;
}

void	print_ans(int n, int *arr, int size)
{
	int	cnt;

	for (cnt = 1; cnt <= 4; cnt++)
		if (calculate(n, arr, size, cnt) == n)
			break;
	printf("%d", i);
}

int	calculate(int n, int *arr, int size, int cnt)
{
	int    sum;
	int    i, j, k, l;

	for (i = 0; i < size; i++)
	{
		sum = arr[i];
		
		if (cnt != 1)
		{
			for (j = 0; j < size; j++)
			{
				sum += arr[j];
				
				if (cnt != 2)
				{
					for (k = 0; k < size; k++)
					{
						sum += arr[k];
						
						if (cnt != 3)
						{
							for (l = 0; l < size; l++)
							{
								sum += arr[l];
								if (sum == n)
									return (sum);
								sum -= arr[l];
							}
						}

						if (sum == n)
							return (sum);
						sum -= arr[k];
					}
				}

				if (sum == n)
					return (sum);
				sum -= arr[j];
			}
		}

		if (sum == n)
			return (sum);
		sum -= arr[i];
	}
	return (sum);
}
