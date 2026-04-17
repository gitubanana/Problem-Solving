#include <iostream>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

enum e_dir
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};

typedef enum e_map
{
	EMPTY,
	WALL,
	CLEANED
}	t_map;

const int	MAX = 50;
// 북, 동, 남, 서
const int	dy[] = {-1, 0, 1, 0};
const int	dx[] = {0, 1, 0, -1};

t_map	map[MAX][MAX];
int		y_size, x_size;

bool	around_not_cleaned(t_pos &cur)
{
	t_pos	around;

	for (int i = 0; i < 4; i++)
	{
		around.y = cur.y + dy[i];
		around.x = cur.x + dx[i];
		if (!(0 <= around.y < y_size) || !(0 <= around.x < x_size))
			continue ;
		if (map[around.y][around.x] == EMPTY)
			return (true);
	}
	return (false);
}

bool	go_back(t_pos &cur, int &dir)
{
	t_pos	next_pos;
	int		reversed_dir;

	reversed_dir = (dir + 2) % 4;
	next_pos.y = cur.y + dy[reversed_dir];
	next_pos.x = cur.x + dx[reversed_dir];
	// 어차피 벽에 둘러싸여 있기 때문에 범위를 벗어날 수 없다.
	if (map[next_pos.y][next_pos.x] == WALL)
		return (false);
	cur = next_pos;
	return (true);
}

void	turn_around_and_go(t_pos &cur, int &dir)
{
	t_pos	next_pos;

	// 반시계 방향 90도
	if (dir == NORTH)
		dir = WEST;
	else
		dir--;
	next_pos.y = cur.y + dy[dir];
	next_pos.x = cur.x + dx[dir];
	if (map[next_pos.y][next_pos.x] == EMPTY)
		cur = next_pos;
}

int	main(void)
{
	int		dir;
	t_pos	cur;
	int		y, x, cleaned_cnt;

	scanf(" %d %d", &y_size, &x_size);
	scanf(" %d %d %d", &cur.y, &cur.x, &dir);
	for (y = 0; y < y_size; y++)
		for (x = 0; x < x_size; x++)
			scanf(" %d", &map[y][x]);
	while (true)
	{
		if (map[cur.y][cur.x] == EMPTY)
			map[cur.y][cur.x] = CLEANED;
		if (around_not_cleaned(cur))
			turn_around_and_go(cur, dir);
		else if (go_back(cur, dir) == false)
			break ;
	}
	cleaned_cnt = 0;
	for (y = 0; y < y_size; y++)
		for (x = 0; x < x_size; x++)
			if (map[y][x] == CLEANED)
				cleaned_cnt++;
	printf("%d\n", cleaned_cnt);
	return (0);
}
