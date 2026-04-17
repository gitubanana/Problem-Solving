#include <queue>
#include <iostream>

typedef struct
{
	int	x;
	int	y;
}	t_pos;

const int	MAX = 201;

int	cnt[MAX][MAX];

//(r - 2, c - 1), (r - 2, c + 1), (r, c - 2), (r, c + 2), (r + 2, c - 1), (r + 2, c + 1)
int	dy[] = {-1, 1, -2, 2, -1, 1};
int	dx[] = {-2, -2, 0, 0, 2, 2};

void	bfs(t_pos &start, t_pos &dest, int &size)
{
	int					i;
	std::queue<t_pos>	q;
	t_pos				cur_pos, next_pos;

	q.push(start);
	while (!q.empty())
	{
		cur_pos = q.front(), q.pop();
		for (i = 0; i < 6; i++)
		{
			next_pos.y = cur_pos.y + dy[i];
			next_pos.x = cur_pos.x + dx[i];
			if (!(0 <= next_pos.y && next_pos.y < size)
				|| !(0 <= next_pos.x && next_pos.x < size)
				|| (cnt[next_pos.y][next_pos.x] != 0))
				continue ;
			cnt[next_pos.y][next_pos.x] = cnt[cur_pos.y][cur_pos.x] + 1;
			q.push(next_pos);
			if (next_pos.y == dest.y && next_pos.x == dest.x)
				return ;
		}
	}
}

int	main(void)
{
	int		size;
	t_pos	start, dest;

	std::cin >> size;
	std::cin >> start.x >> start.y >> dest.x >> dest.y;
	bfs(start, dest, size);
	if (cnt[dest.y][dest.x] == 0)
		std::cout << -1;
	else
		std::cout << cnt[dest.y][dest.x];
	return (0);
}