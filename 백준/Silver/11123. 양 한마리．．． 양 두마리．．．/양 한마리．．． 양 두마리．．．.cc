#include <iostream>

const int	MAX = 100;

char	map[MAX][MAX + 1];
int		y_size, x_size;
//위, 아래, 오른쪽, 왼쪽
int		dy[] = {-1, 1, 0, 0};
int		dx[] = {0, 0, 1, -1};

void	dfs(int y, int x)
{
	if (!(0 <= y && y < y_size)
		|| !(0 <= x && x < x_size)
		|| map[y][x] != '#')
		return ;
	map[y][x] = '.';
	for (int i = 0; i < 4; i++)
		dfs(y + dy[i], x + dx[i]);
}

int	main(void)
{
	int	y, x;
	int	test_cnt, cnt;

	std::cin >> test_cnt;
	while (test_cnt--)
	{
		std::cin >> y_size >> x_size;
		for (y = 0; y < y_size; y++)
			for (x = 0; x < x_size; x++)
				std::cin >> map[y][x];
		cnt = 0;
		for (y = 0; y < y_size; y++)
			for (x = 0; x < x_size; x++)
				if (map[y][x] == '#')
					dfs(y, x), cnt++;
		std::cout << cnt << std::endl;
	}
	return (0);
}