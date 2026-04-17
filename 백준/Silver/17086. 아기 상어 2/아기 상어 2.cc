#include <queue>
#include <cstring>
#include <iostream>

const int	MAX = 50;
const int	SHARK = 1;

int	max_dist;
int	y_size, x_size;
int	map[MAX][MAX];
int	cnt[MAX][MAX];
//위, 아래, 오른쪽, 왼쪽, 위+오른쪽, 위+왼쪽, 아래+오른쪽, 아래+왼쪽
int	dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int	dx[] = {0, 0, 1, -1, 1, -1, 1, -1};

void	bfs(int y, int x)
{
	std::queue<std::pair<int, int> >	q;
	std::pair<int, int>					cur_pos;
	int	i, next_y, next_x;

	q.push({y, x});
	while (!q.empty())
	{
		cur_pos = q.front(), q.pop();
		for (i = 0; i < 8; i++)
		{
			next_y = cur_pos.first + dy[i];
			next_x = cur_pos.second + dx[i];
			if (!(0 <= next_y && next_y < y_size)
				|| !(0 <= next_x && next_x < x_size)
				|| cnt[next_y][next_x] != 0)
				continue ;
			cnt[next_y][next_x] = cnt[cur_pos.first][cur_pos.second] + 1;
			if (map[next_y][next_x] == SHARK)
			{
				max_dist = std::max(max_dist, cnt[next_y][next_x]);
				return ;
			}
			q.push({next_y, next_x});
		}
	}
}

int	main(void)
{
	int	y, x, idx;

	idx = 0;
	std::cin >> y_size >> x_size;
	for (y = 0; y < y_size; y++)
		for (x = 0; x < x_size; x++)
			std::cin >> map[y][x];
	for (y = 0; y < y_size; y++)
		for (x = 0; x < x_size; x++)
			if (map[y][x] != SHARK)
				memset(cnt, 0, sizeof(cnt)), bfs(y, x);
	std::cout << max_dist;
	return (0);
}