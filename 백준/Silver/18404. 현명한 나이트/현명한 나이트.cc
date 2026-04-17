#include <iostream>
#include <queue>

typedef struct
{
	int	y;
	int	x;
}	t_pos;

const int	MAX = 501;

int		map[MAX][MAX];
t_pos	opp[MAX * MAX];
int	dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int	dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};

void	bfs(t_pos &start, int &size)
{
	int					i;
	std::queue<t_pos>	q;
	t_pos				cur_pos, next_pos;

	// start로 다시 올 때도 생각
	q.push(start);
	while (!q.empty())
	{
		cur_pos = q.front(), q.pop();
		for (i = 0; i < 8; i++)
		{
			next_pos.y = cur_pos.y + dy[i];
			next_pos.x = cur_pos.x + dx[i];
			if (!(1 <= next_pos.y && next_pos.y <= size)
				|| !(1 <= next_pos.x && next_pos.x <= size)
				|| map[next_pos.y][next_pos.x] != 0
				|| (next_pos.y == start.y && next_pos.x == start.x))
				continue ;
			q.push(next_pos);
			map[next_pos.y][next_pos.x] = map[cur_pos.y][cur_pos.x] + 1;
		}
	}
}

int	main(void)
{
	t_pos	start;
	int		i, size, opp_cnt;

	scanf(" %d %d", &size, &opp_cnt);
	scanf(" %d %d", &start.y, &start.x);
	for (i = 0; i < opp_cnt; i++)
		scanf(" %d %d", &opp[i].y, &opp[i].x);
	bfs(start, size);
	for (i = 0; i < opp_cnt; i++)
		printf("%d ", map[opp[i].y][opp[i].x]);
	return (0);
}
