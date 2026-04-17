#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int	cmp(const void *a, const void *b)
{
	return (*(int *)a > *(int *)b);
}

int	main(void)
{
	int			i;
	uint64_t	sum;
	int			*arr, size;

	scanf("%d", &size);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (perror(""), 1);
	for (i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	qsort(arr, size, sizeof(int), cmp);
	for (i = 0, sum = 0; i < size; i++)
		sum += abs(arr[i] - (i + 1));
	printf("%llu", sum);
	return (0);
}