#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#define MAX 101

char	maze[MAX - 1][MAX];
int		cnt[MAX - 1][MAX];
int		dx[4] = {1, -1, 0, 0};
int		dy[4] = {0, 0, 1, -1};

void	enqueue(int *queue, int *tail, int data)
{
	queue[*tail] = data;
	*tail = *tail + 1;
}

void	bfs(int row_size, int col_size)
{
	int	i, head, tail;
	int	cur_x, cur_y;
	int	queue[200000];

	head = tail = 0;
	//행, 열 차례대로 큐에 넣기
	enqueue(queue, &tail, 0);
	enqueue(queue, &tail, 0);
	while (head <= tail)
	{
		for (i = 0; i < 4; i++)
		{
			cur_x = queue[head] + dx[i];
			cur_y = queue[head + 1] + dy[i];
			if ((cur_x < 0 || cur_x >= row_size)
				|| (cur_y < 0 || cur_y >= col_size)
				|| maze[cur_x][cur_y] == '0'
				|| cnt[cur_x][cur_y] != 0)
				continue ;
			enqueue(queue, &tail, cur_x);
			enqueue(queue, &tail, cur_y);
			cnt[cur_x][cur_y] += cnt[queue[head]][queue[head + 1]] + 1;
			if (cur_x == row_size - 1 && cur_y == col_size - 1)
				return ;
		}
		head = head + 2;
	}
}

int	main(void)
{
	int	i;
	int	row_size, col_size;

	scanf("%d %d", &row_size, &col_size);
	for (i = 0; i < row_size; i++)
		scanf("%s", maze[i]);
	bfs(row_size, col_size);
	printf("%d", cnt[row_size - 1][col_size - 1] + 1);
	return (0);
}