#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#define MAX 100001

int	pos[MAX];

void	push(int *queue, int *tail, int data)
{
	queue[*tail] = data;
	(*tail)++;
}

void	bfs(int subin, int dongsaeng)
{
	int	i, head, tail;
	int	queue[MAX];
	int	x[3];

	head = tail = 0;
	queue[tail++] = subin;
	if (subin == dongsaeng)
		return ;
	while (1)
	{
		x[0] = queue[head] + 1;
		x[1] = queue[head] - 1;
		x[2] = queue[head] * 2;
		for (i = 0; i < 3; i++)
		{
			if (x[i] < 0 || x[i] > MAX || pos[x[i]] != 0)
				continue ;
			push(queue, &tail, x[i]);
			pos[x[i]] = pos[queue[head]] + 1;
			if (x[i] == dongsaeng)
				return ;
		}
		head++;
	}
}

int	main(void)
{
	int	subin, dongsaeng;

	scanf("%d %d", &subin, &dongsaeng);
	bfs(subin, dongsaeng);
	printf("%d", pos[dongsaeng]);
	return (0);
}
