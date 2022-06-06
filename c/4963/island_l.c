#include <stdio.h>
#include <stdlib.h>
#define LAND 1

int	init_2D(int ***p_arr, int w, int h);
void	scan_map(int **map, int w, int h);
void	dfs(int **map, int w, int h, int i, int j);
void	print_island_cnt(int **map, int w, int h);
void	free_2D(int **arr, int size);

int	main(void)
{
	int	width;
	int	height;
	int	**map;

	while (1)
	{
		scanf("%d %d", &width, &height);
		if (width == 0)
			break;
		if (!init_2D(&map, width, height))
			return (1);
		scan_map(map, width, height);
		print_island_cnt(map, width, height);
		free_2D(map, height);
	}
	return (0);
}

int	init_2D(int ***p_arr, int w, int h)
{
	int	i;

	*p_arr = malloc(sizeof(int *) * h);
	if (!*p_arr)
		return (0);
	for (i = 0; i < h; i++)
	{
		(*p_arr)[i] = malloc(sizeof(int) * w);
		if (!(*p_arr)[i])
			return (0);
	}
	return (1);
}

void	scan_map(int **map, int w, int h)
{
	int	i, j;

	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			scanf("%d", &map[i][j]);
}

void	print_island_cnt(int **map, int w, int h)
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
				dfs(map, w, h, i, j);
			}
		}
	}
	printf("%d\n", cnt);
}

void	dfs(int **map, int w, int h, int i, int j)
{
	map[i][j] = 0;

	//up
	if (i > 0 && map[i - 1][j] == LAND)
		dfs(map, w, h, i - 1, j);

	//down
	if (i < h - 1 && map[i + 1][j] == LAND)
		dfs(map, w, h, i + 1, j);

	//left
	if (j > 0 && map[i][j - 1] == LAND)
		dfs(map, w, h, i, j - 1);

	//right
	if (j < w - 1 && map[i][j + 1] == LAND)
		dfs(map, w, h, i, j + 1);

	//up + right
	if (i > 0 && j < w - 1 && map[i - 1][j + 1] == LAND)
		dfs(map, w, h, i - 1, j + 1);

	//up + left
	if (i > 0 && j > 0 && map[i - 1][j - 1] == LAND)
		dfs(map, w, h, i - 1, j - 1);

	//down + right
	if (i < h - 1 && j < w - 1 && map[i + 1][j + 1] == LAND)
		dfs(map, w, h, i + 1, j + 1);

	//down + left
	if (i < h - 1 && j > 0 && map[i + 1][j - 1] == LAND)
		dfs(map, w, h, i + 1, j - 1);
}

void	free_2D(int **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}
