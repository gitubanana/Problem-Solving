#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int	cmp(const void *a, const void *b)
{
	return (*(int *)a > *(int *)b);
}

void	print_max_weight(int *arr, int size)
{
	int			i;
	uint64_t	tmp, max;

	qsort(arr, size, sizeof(int), cmp);
	max = 0;
	for (i = 0; i < size; i++)
	{
		tmp = arr[i] * (size - i);
		if (max < tmp)
			max = tmp;
	}
	printf("%llu", max);
}

int	main(void)
{
	int	*arr, size;

	scanf("%d", &size);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (perror(""), 1);
	for (int i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	print_max_weight(arr, size);
	return (free(arr), 0);
}