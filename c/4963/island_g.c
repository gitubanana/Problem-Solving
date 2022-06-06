#include <stdio.h>
#define LAND 1

int	map[50][50];

void	scan_map(int w, int h)
void	dfs(int w, int h, int i, int j);
void	print_island_cnt(int w, int h);

int	main(void)
{
	int	width;
	int	height;

	while (1)
	{
		scanf("%d %d", &width, &height);
		if (width == 0)
			break;
		scan_map(width, height);
		print_island_cnt(width, height);
	}
}

void	scan_map(int w, int h)
{
	int	i, j;

	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			scanf("%d", &map[i][j]);
}

void	print_island_cnt(int w, int h)
{
	int	i, j;
	int	cnt;

	cnt = 0;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (map[i][j] == LAND)
			{
				cnt++;
				dfs(w, h, i, j);
			}
		}
	}
	printf("%d\n", cnt);
}

void	dfs(int	w, int h, int i, int j)
{
	map[i][j] = 0;

	//up
	if (i > 0 && map[i - 1][j] == LAND)
		dfs(w, h, i - 1, j);

	//down
	if (i < h - 1 && map[i + 1][j] == LAND)
		dfs(w, h, i + 1, j);

	//left
	if (j > 0 && map[i][j - 1] == LAND)
		dfs(w, h, i, j - 1);

	//right
	if (j < w - 1 && map[i][j + 1] == LAND)
		dfs(w, h, i, j + 1);

	//up + right
	if (i > 0 && j < w - 1 && map[i - 1][j + 1] == LAND)
		dfs(w, h, i - 1, j + 1);

	//up + left
	if (i > 0 && j > 0 && map[i - 1][j - 1] == LAND)
		dfs(w, h, i - 1, j - 1);

	//down + right
	if (i < h - 1 && j < w - 1 && map[i + 1][j + 1] == LAND)
		dfs(w, h, i + 1, j + 1);

	//down + left
	if (i < h - 1 && j > 0 && map[i + 1][j - 1] == LAND)
		dfs(w, h, i + 1, j - 1);
}
