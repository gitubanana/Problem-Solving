#include <stdio.h>

void	print_ans(int v_cnt);
int	is_searchable(int v, int v_cnt);
void	search(int v, int v_cnt);

int	matrix[1001][1001];
int	visited[1001];

int	main(void)
{
	int	a;
	int	b;
	int	vertex;
	int	edge;

	scanf("%d %d", &vertex, &edge);
	while (edge--)
	{
		scanf("%d %d", &a, &b);
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}
	print_ans(vertex);
}

void	print_ans(int v_cnt)
{
	int	i;
	int	cnt;

	cnt = 0;
	for(i = 1; i <= v_cnt; i++)
	{
		if (is_searchable(i, v_cnt))
			cnt++;
	}
	printf("%d", cnt);
}

int	is_searchable(int v, int v_cnt)
{
	if (visited[v] == 1)
		return (0);
	search(v, v_cnt);
	return (1);
}

void	search(int v, int v_cnt)
{
	int	i;

	for (i = 1; i <= v_cnt; i++)
	{
		if (matrix[v][i] == 1 && visited[i] == 0)
		{
			visited[i] = 1;
			search(i, v_cnt);
		}
	}
}
