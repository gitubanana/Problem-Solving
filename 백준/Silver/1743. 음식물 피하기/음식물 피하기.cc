#include <iostream>
#include <algorithm>

typedef struct 
{
	int	y;
	int	x;
}	t_pos;

const int	MAX = 101;
const char	TARGET = '#';

char	map[MAX][MAX];
// 위, 아래, 오른쪽, 왼쪽
int	dy[] = {1, -1, 0, 0};
int	dx[] = {0, 0, 1, -1};

void	dfs(int y, int x, int *tmp, int &y_size, int &x_size)
{
	int	i;

	if (!(1 <= y && y <= y_size)
		|| !(1 <= x && x <= x_size)
		|| map[y][x] != TARGET)
		return ;

	(*tmp)++;
	map[y][x] = 0;
	for (i = 0; i < 4; i++)
		dfs(y + dy[i], x + dx[i], tmp, y_size, x_size);
}


int	main(void)
{
	int	y_size, x_size, y, x;
	int	target_cnt, max_size, tmp;

	scanf(" %d %d %d", &y_size, &x_size, &target_cnt);
	while (target_cnt--)
	{
		scanf(" %d %d", &y, &x);
		map[y][x] = TARGET;
	}
	max_size = 0;
	for (y = 1; y <= y_size; y++)
	{
		for (x = 1; x <= x_size; x++)
		{
			if (map[y][x] == TARGET)
			{
				tmp = 0;
				dfs(y, x, &tmp, y_size, x_size);
				max_size = std::max(max_size, tmp);
			}
		}
	}
	printf("%d\n", max_size);
	return (0);
}
