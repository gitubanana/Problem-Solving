#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

const int	MAX = 128;

int	map[MAX][MAX];
int	white, blue;

bool	check_blue(int &start_y, int &start_x, int size)
{
	int	y, x;
	int	y_size, x_size;

	y_size = start_y + size;
	x_size = start_x + size;
	for (y = start_y; y < y_size; ++y)
		for (x = start_x; x < x_size; ++x)
			if (map[y][x] != 1)
				return (false);
	++blue;
	return (true);
}

bool	check_white(int &start_y, int &start_x, int size)
{
	int	y, x;
	int	y_size, x_size;

	y_size = start_y + size;
	x_size = start_x + size;
	for (y = start_y; y < y_size; ++y)
		for (x = start_x; x < x_size; ++x)
			if (map[y][x] != 0)
				return (false);
	++white;
	return (true);
}

void	count_recursive(int start_y, int start_x, int size)
{
	int	next_size = size / 2;

	if (check_blue(start_y, start_x, size))
		return ;
	if (check_white(start_y, start_x, size))
		return ;
	// 왼쪽 위
	count_recursive(start_y, start_x, next_size);
	// 왼쪽 아래
	count_recursive(start_y + next_size, start_x, next_size);
	// 오른쪽 위
	count_recursive(start_y, start_x + next_size, next_size);
	// 오른쪽 아래
	count_recursive(start_y + next_size, start_x + next_size, next_size);
}

int main(void)
{
	int	y, x;
	int	size;

	scanf(" %d", &size);
	for (y = 0; y < size; ++y)
		for (x = 0; x < size; ++x)
			scanf(" %d", &map[y][x]);
	count_recursive(0, 0, size);
	printf("%d\n%d\n", white, blue);
	return (0);
}