#include <stdio.h>
#include <stdlib.h>

int	get_sum(int *arr, int size);

int	main(void)
{
	int	n, tmp;
	int	top = -1;
	int	*stack;

	scanf("%d", &n);
	stack = calloc(n, sizeof(int));
	if (!stack)
		exit(-1);
	while (n--)
	{
		scanf("%d", &tmp);
		if (tmp == 0 && top > -1)
			stack[top--] = 0;
		else
			stack[++top] = tmp;
	}
	printf("%d", get_sum(stack, top + 1));
	free(stack);
	exit(0);
}

int	get_sum(int *arr, int size)
{
	int	i, sum;

	sum = 0;
	for (i = 0; i < size; i++)
		sum += arr[i];
	return sum;
}
