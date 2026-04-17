#include <iostream>
#include <cstring>

const int	MAX = 51;
const int	CABBAGE = 1, FALSE = 0, TRUE = 1;
int			land[MAX][MAX];
int			visited[MAX][MAX];
int			 x_size, y_size;
//위, 아래, 오른쪽, 왼쪽
int			dy[] = {1, -1, 0, 0};
int			dx[] = {0, 0, 1, -1};

void	dfs(int y, int x)
{
	if (!(0 <= y && y < y_size) || !(0 <= x && x < x_size)
		|| land[y][x] != CABBAGE || visited[y][x] == TRUE)
		return ;
	visited[y][x] = TRUE;
	for (int i = 0; i < 4; i++)
		dfs(y + dy[i], x + dx[i]);
}

void	print_worm_cnt(int x_size, int y_size)
{
	int	x, y;
	int	worm_cnt;

	worm_cnt = 0;
	for (y = 0; y < y_size; y++)
	{
		for (x = 0; x < x_size; x++)
		{
			if (land[y][x] == CABBAGE && visited[y][x] == FALSE)
				dfs(y, x), worm_cnt++;
		}
	}
	printf("%d\n", worm_cnt);
}

int main(void)
{
	int	test_cnt;
	int	x, y;
	int	i, cabbage_cnt;

	scanf("%d", &test_cnt);
	while (test_cnt--)
	{
		scanf("%d %d %d", &x_size, &y_size, &cabbage_cnt);
		for (i = 0; i < y_size; i++)
		{
			memset(land[i], 0, sizeof(int) * x_size);
			memset(visited[i], 0, sizeof(int) * x_size);
		}
		for (i = 0; i < cabbage_cnt; i++)
		{
			scanf("%d %d", &x, &y);
			land[y][x] = CABBAGE;
		}
		print_worm_cnt(x_size, y_size);
	}
	return (0);
}