#include <stdio.h>
#include <stdlib.h>

void	insertion_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < size)
	{
		j = i;
		tmp = arr[j];
		while (--j >= 0 && arr[j] > tmp)
		{
			arr[j + 1] = arr[j];
			arr[j] = tmp;
		}
		i++;
	}
}

void	print_min(int *arr, int size)
{
	int	i;
	int	tmp;
	int	sum;

	i = 0;
	tmp = 0;
	sum = 0;
	while (i < size)
	{
		tmp += arr[i];
		sum += tmp;
		i++;
	}
	printf("%d", sum);
}

int	main(void)
{
	int	i;
	int	n;
	int	*time;

	i = 0;
	scanf("%d", &n);
	time = malloc(sizeof(int) * n);
	if (!time)
		return (1);
	while (i < n)
		scanf("%d", &time[i++]);
	insertion_sort(time, n);
	print_min(time, n);
	free(time);
	return (0);
}
