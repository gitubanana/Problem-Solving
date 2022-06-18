#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int	n; //num
	int	s; //score
}sco; //score

int	cmp1(const void *a, const void *b)
{
	return ((sco *)b)->s - ((sco *)a)->s;
}

void	print_score(sco *arr, int size)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	qsort(arr, size, sizeof(sco), cmp1);
	while (i < 5)
		sum += arr[i++].s;
	printf("%d\n", sum);
}

int	cmp2(const void *a, const void *b)
{
	return ((sco *)a)->n - ((sco *)b)->n;
}

void	print_num(sco *arr, int size)
{
	int	i;

	i = 0;
	qsort(arr, size, sizeof(sco), cmp2);
	while (i < size)
		printf("%d ", arr[i++].n);
}

int	main(void)
{
	int	i;
	sco	*arr;

	i = 0;
	arr = malloc(sizeof(sco) * 8);
	if (!arr)
		return (1);
	while (i < 8)
	{
		scanf("%d", &arr[i].s);
		arr[i].n = i + 1;
		i++;
	}
	print_score(arr, 8);
	print_num(arr, 5);
	free(arr);
	return (0);
}
