#include <stdio.h>

void	init_visited();
void	print_dfs(int v, int v_cnt);
void	print_bfs(int v, int v_cnt);

int	matrix[1001][1001];
int	visited[1001];

int	main(void)
{
	int	a, b;
	int	v, v_cnt, e_cnt;

	scanf("%d %d %d", &v_cnt, &e_cnt, &v);
	while (e_cnt--)
	{
		scanf("%d %d", &a, &b);
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}
	print_dfs(v, v_cnt);
	printf("\n");
	init_visited();
	print_bfs(v, v_cnt);
}

void	print_dfs(int v, int v_cnt)
{
	int	i;

	printf("%d ", v);
	visited[v] = 1;
	for (i = 1; i <= v_cnt; i++)
		if (matrix[v][i] == 1 && visited[i] == 0)
			print_dfs(i, v_cnt);
}

void	init_visited()
{
	int	i;

	i = 1;
	while (i < 1001)
		visited[i++] = 0;
}

void	print_bfs(int v, int v_cnt)
{
	int	i;
	int	h, t; //head, tail
	int	q[10001]; //queue

	h = 0;
	t = 0;
	visited[v] = 1;
	while (h <= t)
	{
		printf("%d ", v);
		for (i = 1; i <= v_cnt; i++)
		{
			if (matrix[v][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				q[t++] = i;
			}
		}
		v = q[h++];
	}
}
