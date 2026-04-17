#include <queue>
#include <iostream>

const int	MAX = 250;
const int	WORD = 1;

int	map[MAX][MAX];
int	x_size, y_size;
//위, 아래, 오른쪽, 왼쪽, 위 + 오른쪽, 위 + 왼쪽, 아래 + 오른쪽, 아래 + 왼쪽
int	dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int	dx[] = {0, 0, 1, -1, 1, -1, 1, -1};

void	dfs(int y, int x)
{
	if (!(0 <= y && y < y_size)
		|| !(0 <= x && x < x_size)
		|| map[y][x] != WORD)
		return ;
	map[y][x] = 0;
	for (int i = 0; i < 8; i++)
		dfs(y + dy[i], x + dx[i]);
}

int	main(void)
{
	int	y, x;
	int	cnt = 0;

	std::cin >> y_size >> x_size;
	for (y = 0; y < y_size; y++)
		for (x = 0; x < x_size; x++)
			std::cin >> map[y][x];
	for (y = 0; y < y_size; y++)
		for (x = 0; x < x_size; x++)
			if (map[y][x] == WORD)
				dfs(y, x), cnt++;
	std::cout << cnt;
	return (0);
}