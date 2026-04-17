#include <iostream>
#include <cstring>
#include <queue>

typedef struct
{
	int	y;
	int	x;
}	t_pos;

const int	MAX = 50;

int		cnt[MAX][MAX];
char	map[MAX][MAX + 1];
// 위, 아래, 오른쪽, 왼쪽
int		dy[] = {1, -1, 0, 0};
int		dx[] = {0, 0, 1, -1};
int		max;

void	bfs(int &y, int &x, int &y_size, int &x_size)
{
	std::queue<t_pos>	q;
	t_pos				cur_pos, next_pos;
	int					i, cur_max = 0;

	q.push({y, x});
	while (!q.empty())
	{
		cur_pos = q.front(), q.pop();
		for (i = 0; i < 4; i++)
		{
			next_pos.y = cur_pos.y + dy[i];
			next_pos.x = cur_pos.x + dx[i];
			if (!(0 <= next_pos.y && next_pos.y < y_size)
				|| !(0 <= next_pos.x && next_pos.x < x_size)
				|| cnt[next_pos.y][next_pos.x] != 0
				|| map[next_pos.y][next_pos.x] != 'L'
				|| (next_pos.y == y && next_pos.x == x))
				continue ;
			q.push(next_pos);
			cnt[next_pos.y][next_pos.x] = cnt[cur_pos.y][cur_pos.x] + 1;
			if (cur_max < cnt[next_pos.y][next_pos.x])
				cur_max = cnt[next_pos.y][next_pos.x];
		}
	}
	if (max < cur_max)
		max = cur_max;
}

int	main(void)
{
	int	y, x;
	int	y_size, x_size;

	scanf(" %d %d", &y_size, &x_size);
	for (y = 0; y < y_size; y++)
		scanf(" %s", map[y]);
	for (y = 0; y < y_size; y++)
		for (x = 0; x < x_size; x++)
			if (map[y][x] == 'L')
				memset(cnt, 0, sizeof(cnt)), bfs(y, x, y_size, x_size);
	printf("%d\n", max);
	return (0);
}
