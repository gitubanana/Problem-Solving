#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int	w; //weight
	int	h; //height
	int	r; //rank
}body;

void	scan_arr(body *arr, int size);
void	make_rank(body *arr, int size);
void	print_ans(body *arr, int size);

int	main(void)
{
	int	n;
	body	*arr;

	scanf("%d", &n);
	arr = malloc(sizeof(body) * n);
	if (!arr)
		return (1);
	scan_arr(arr, n);
	print_ans(arr, n);
	free(arr);
	return (0);
}

void	scan_arr(body *arr, int size)
{
	int	i;

	for (i = 0; i < size; i++)
		scanf("%d %d", &arr[i].w, &arr[i].h);
}

void	print_ans(body *arr, int size)
{
	int	i;

	make_rank(arr, size);
	for (i = 0; i < size; i++)
		printf("%d ", arr[i].r);
}

void	make_rank(body *arr, int size)
{
	int	i;
	int	j;
	int	rank;

	for (i = 0; i < size; i++)
	{
		rank = 1;
		for (j = 0; j < size; j++)
			if (arr[i].w < arr[j].w && arr[i].h < arr[j].h)
				rank++;
		arr[i].r = rank;
	}
}
