#include <iostream>
#include <cstring>

// 거북이 명령
// 		F : 한 눈금 앞으로
//		B : 한 눈금 뒤로
//		L : 왼쪽으로 90도
//		R : 오른쪽으로 90도

typedef struct
{
	int	y, x;
}	t_pos;

// 동, 북, 서, 남
enum e_dir
{
	EAST,
	NORTH,
	WEST,
	SOUTH
};

// 동, 북, 서, 남
int	dy[] = {0, 1, 0, -1};
int	dx[] = {1, 0, -1, 0};

void	do_cmd(int &dir, t_pos &cur, char cmd)
{
	int	back_dir;

	if (cmd == 'F')
	{
		cur.y += dy[dir];
		cur.x += dx[dir];
	}
	else if (cmd == 'B')
	{
		if (dir == EAST)
			back_dir = WEST;
		else if (dir == WEST)
			back_dir = EAST;
		else if (dir == NORTH)
			back_dir = SOUTH;
		else
			back_dir = NORTH;
		cur.y += dy[back_dir];
		cur.x += dx[back_dir];
	}
	else if (cmd == 'L')
	{
		if (dir == SOUTH)
			dir = EAST;
		else
			++dir;
	}
	else if (cmd == 'R')
	{
		if (dir == EAST)
			dir = SOUTH;
		else
			--dir;
	}
}

int	get_rectangle_size(char *cmd)
{
	t_pos	cur = {0, 0};
	t_pos	max = {0, 0};
	t_pos	min = {0, 0};
	int		dir = NORTH;

	for (int i = 0; cmd[i]; ++i)
	{
		do_cmd(dir, cur, cmd[i]);
		if (max.y < cur.y)
			max.y = cur.y;

		if (max.x < cur.x)
			max.x = cur.x;

		if (min.y > cur.y)
			min.y = cur.y;

		if (min.x > cur.x)
			min.x = cur.x;
	}
	return ((max.y - min.y) * (max.x - min.x));
}

int	main(void)
{
	int		test_cnt;
	char	cmd[501];

	scanf(" %d", &test_cnt);
	while (test_cnt)
	{
		scanf(" %s", cmd);
		printf("%d\n", get_rectangle_size(cmd));
		--test_cnt;
	}
	return (0);
}
