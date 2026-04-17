#include <cstring>
#include <iostream>

const int	MAX = 100;

int	land[MAX][MAX];
int	visited[MAX][MAX];
//위, 아래, 오른쪽, 왼쪽
int	dy[] = {-1, 1, 0, 0};
int	dx[] = {0, 0, 1, -1};

void	dfs(int &max_height, int &size, int y, int x)
{
	if (!(0 <= y && y < size) || !(0 <= x && x < size)
		|| (visited[y][x] == 1) || (land[y][x] <= max_height))
		return ;
	
	/* 방문 표시 */
	visited[y][x] = 1;

	/* 위, 아래, 오른쪽, 왼쪽 */
	for (int i = 0; i < 4; i++)
		dfs(max_height, size, y + dy[i], x + dx[i]);
}

void	print_max_safety_zone(int &max_height, int &size)
{
	int	y, x;
	int	max_safety_zone, cur_safety_zone;

	max_safety_zone = 1;
	while (max_height--)
	{
		cur_safety_zone = 0;
		for (y = 0; y < size; y++)
			for (x = 0; x < size; x++)
				if (land[y][x] > max_height && visited[y][x] == 0)
					cur_safety_zone++, dfs(max_height, size, y, x);
		if (max_safety_zone < cur_safety_zone)
			max_safety_zone = cur_safety_zone;
		memset(visited, 0, sizeof(visited));
	}
	std::cout << max_safety_zone;
}

int	main(void)
{
	int	y, x, size;
	int	max_height;

	max_height = 0;
	std::cin >> size;
	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			std::cin >> land[y][x];
			if (max_height < land[y][x])
				max_height = land[y][x];
		}
	}
	print_max_safety_zone(max_height, size);
	return (0);
}