#include <iostream>
#include <vector>
#include <algorithm>

typedef struct s_pos
{
	int	y, x;
}	t_pos;


const int	MAX = 101;

int	map[MAX][MAX];
int	y_size, x_size;
// 동, 북, 서, 남
int	dy[] = {0, 1, 0, -1};
int	dx[] = {1, 0, -1, 0};

void	dfs(int y, int x, int &tmp)
{
	if (!(0 <= y && y < y_size)
		|| !(0 <= x && x < x_size)
		|| map[y][x] != 0)
		return ;
	++tmp;
	map[y][x] = 1;
	for (int i = 0; i < 4; ++i)
		dfs(y + dy[i], x + dx[i], tmp);
}

int	main(void)
{
	std::vector<int>	size;
	t_pos				start, end;
	int					cnt, y, x, tmp;

	scanf(" %d %d %d", &y_size, &x_size, &cnt);
	while(cnt)
	{
		scanf(" %d %d", &start.x, &start.y);
		scanf(" %d %d", &end.x, &end.y);
		for (y = start.y; y < end.y; ++y)
			for (x = start.x; x < end.x; ++x)
				map[y][x] = 1;
		--cnt;
	}
	cnt = 0;
	for (y = 0; y < y_size; ++y)
		for (x = 0; x < x_size; ++x)
			if (map[y][x] == 0)
				++cnt, tmp = 0, dfs(y, x, tmp), size.push_back(tmp);
	printf("%d\n", cnt);
	std::sort(size.begin(), size.end());
	for (const int &elem : size)
		printf("%d ", elem);
	printf("\n");
	return (0);
}
