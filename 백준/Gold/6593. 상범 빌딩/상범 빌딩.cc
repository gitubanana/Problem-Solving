#include <iostream>
#include <queue>
#include <cstring>

typedef struct s_3D
{
	int	z;
	int	y;
	int	x;

	bool	operator==(struct s_3D &b)
	{
		return (this->z == b.z && this->y == b.y && this->x == b.x);
	}
}	t_3D;

const int	MAX = 30;
const char	START = 'S';
const char	END = 'E';
const char	WALL = '#';

int		cnt[MAX][MAX][MAX];
char	building[MAX][MAX][MAX + 1];

// 동, 서, 남, 북, 상, 하
int	dz[] = {0, 0, 0, 0, 1, -1};
int	dy[] = {0, 0, -1, 1, 0, 0};
int	dx[] = {1, -1, 0, 0, 0, 0};

bool	bfs(t_3D &size, t_3D &start, t_3D &end)
{
	int					i;
	std::queue<t_3D>	q;
	t_3D				cur_pos, next_pos;

	// start visited 확인
	cnt[start.z][start.y][start.x] = 0;
	building[start.z][start.y][start.x] = WALL;
	q.push(start);
	while (!q.empty())
	{
		cur_pos = q.front(), q.pop();
		for (i = 0; i < 6; ++i)
		{
			next_pos.z = cur_pos.z + dz[i];
			next_pos.y = cur_pos.y + dy[i];
			next_pos.x = cur_pos.x + dx[i];
			if (!(0 <= next_pos.z && next_pos.z < size.z)
				|| !(0 <= next_pos.y && next_pos.y < size.y)
				|| !(0 <= next_pos.x && next_pos.x < size.x)
				|| building[next_pos.z][next_pos.y][next_pos.x] == WALL
				|| cnt[next_pos.z][next_pos.y][next_pos.x] != 0)
				continue ;
			cnt[next_pos.z][next_pos.y][next_pos.x] = cnt[cur_pos.z][cur_pos.y][cur_pos.x] + 1;
			if (end == next_pos)
				return (true);
			q.push(next_pos);
		}
	}
	return (false);
}

int	main(void)
{
	t_3D	size;
	int		z, y, x;
	int		found_cnt;
	t_3D	start, end;

	while (1)
	{
		scanf(" %d %d %d", &size.z, &size.y, &size.x);
		if (size.x == 0)
			break ;
		found_cnt = 0;
		for (z = 0; z < size.z; ++z)
		{
			for (y = 0; y < size.y; ++y)
			{
				scanf(" %s", building[z][y]);
				for (x = 0; x < size.x && found_cnt != 2; ++x)
				{
					if (building[z][y][x] == START)
						start = {z, y, x}, ++found_cnt;
					else if (building[z][y][x] == END)
						end = {z, y, x}, ++found_cnt;
				}
			}
		}
		if (bfs(size, start, end))
			printf("Escaped in %d minute(s).\n", cnt[end.z][end.y][end.x]);
		else
			printf("Trapped!\n");
		memset(cnt, 0, sizeof(cnt));
	}
	return (0);
}
