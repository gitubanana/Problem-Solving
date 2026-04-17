#include <iostream>
#include <queue>

typedef struct
{
	int	y;
	int	x;
}	t_pos;

const int	SIZE = 5;

int		map[SIZE][SIZE];
int		cnt[SIZE][SIZE];

// 위, 아래, 오른쪽, 왼쪽
// 위 + 오른쪽, 위 + 왼쪽
// 아래 + 오른쪽, 아래 + 왼쪽
int	dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int	dx[] = {0, 0, 1, -1, 1, -1, 1, -1};

int	bfs(t_pos start)
{
	int					i;
	std::queue<t_pos>	q;
	t_pos				cur_pos, next_pos;

	q.push(start);
	while (!q.empty())
	{
		cur_pos = q.front(), q.pop();
		for (i = 0; i < 4; i++)
		{
			next_pos.y = cur_pos.y + dy[i];
			next_pos.x = cur_pos.x + dx[i];
			if (!(0 <= next_pos.y && next_pos.y < SIZE)
				|| !(0 <= next_pos.x && next_pos.x < SIZE)
				|| map[next_pos.y][next_pos.x] == -1
				|| cnt[next_pos.y][next_pos.x] != 0)
				continue ;
			q.push(next_pos);
			if (map[next_pos.y][next_pos.x] == 1)
				return (cnt[cur_pos.y][cur_pos.x] + 1);
			cnt[next_pos.y][next_pos.x] = cnt[cur_pos.y][cur_pos.x] + 1;
		}
	}
	return (-1);
}

int	main(void)
{
	int		y, x;
	t_pos	start;

	for (y = 0; y < SIZE; y++)
		for (x = 0; x < SIZE; x++)
			scanf(" %d", &map[y][x]);
	scanf(" %d %d", &start.y, &start.x);
	printf("%d\n", bfs(start));
	return (0);
}
