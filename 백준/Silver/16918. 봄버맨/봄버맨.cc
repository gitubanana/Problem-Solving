#include <iostream>

const int	MAX = 200;
const char	EMPTY = '.';
char		NEW_BOMB = 'n';
char		OLD_BOMB = 'O';

char	map[MAX][MAX + 1];
int		y_size, x_size, sec;

// 위, 아래, 오른쪽, 왼쪽
const int	dy[] = {-1, 1, 0, 0};
const int	dx[] = {0, 0, 1, -1};

void	print_map(int &y, int &x)
{
	for (y = 0; y < y_size; ++y)
	{
		for (x = 0; x < x_size; ++x)
		{
			if (map[y][x] == NEW_BOMB || map[y][x] == OLD_BOMB)
				printf("%c", 'O');
			else
				printf("%c", map[y][x]);
		}
		printf("\n");
	}
}

void	make_new_bomb(int &y, int &x)
{
	sec--;
	for (y = 0; y < y_size; ++y)
		for (x = 0; x < x_size; ++x)
			if (map[y][x] == EMPTY)
				map[y][x] = NEW_BOMB;
}

void	bomb(int y, int x)
{
	int	next_y, next_x;

	map[y][x] = EMPTY;
	for (int i = 0; i < 4; ++i)
	{
		next_y = y + dy[i];
		next_x = x + dx[i];
		if (!(0 <= next_y && next_y < y_size)
			|| !(0 <= next_x && next_x < x_size)
			|| map[next_y][next_x] == OLD_BOMB)
			continue ;
		map[next_y][next_x] = EMPTY;
	}
}

void	make_explosion(int &y, int &x)
{
	sec--;
	for (y = 0; y < y_size; ++y)
		for (x = 0; x < x_size; ++x)
			if (map[y][x] == OLD_BOMB)
				bomb(y, x);
}

void	swap(char &a, char &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}

int	main(void)
{
	int	y, x;

	scanf(" %d %d %d", &y_size, &x_size, &sec);
	for (y = 0; y < y_size; ++y)
		scanf(" %s", map[y]);
	sec--;
	while (sec)
	{
		make_new_bomb(y, x);
		if (sec == 0)
			break ;
		make_explosion(y, x);
		swap(OLD_BOMB, NEW_BOMB);
	}
	print_map(y, x);
	return (0);
}
