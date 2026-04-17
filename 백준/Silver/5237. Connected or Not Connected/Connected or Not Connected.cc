#include <iostream>
#include <cstring>

const int	MAX = 100, IS_LINKED = 1, VISITED = -1;

int	map[MAX][MAX];

void	dfs(int cur_v, int *&visited, int &v_cnt)
{
	int	i;

	visited[cur_v] = VISITED;
	for (i = 0; i < v_cnt; i++)
		if (map[cur_v][i] == IS_LINKED && visited[i] != VISITED)
			dfs(i, visited, v_cnt);
}

void	print_ans(int &v_cnt)
{
	int	i;
	int	*visited;

	visited = new int[v_cnt];
	memset(visited, 0, sizeof(int) * v_cnt);
	dfs(0, visited, v_cnt);
	for (i = 0; i < v_cnt; i++)
		if (visited[i] != VISITED)
			break ;
	if (i == v_cnt)
		printf("Connected.\n");
	else
		printf("Not connected.\n");
	delete[] visited;
}

int	main(void)
{
	int	test_cnt;
	int	v_cnt, e_cnt, a, b;

	scanf(" %d", &test_cnt);
	while (test_cnt--)
	{
		scanf(" %d %d", &v_cnt, &e_cnt);
		memset(map, 0, sizeof(map));
		while (e_cnt--)
		{
			scanf(" %d %d", &a, &b);
			map[a][b] = IS_LINKED;
			map[b][a] = IS_LINKED;
		}
		print_ans(v_cnt);
	}
	return (0);
}
