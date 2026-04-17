#include <iostream>

const int	MAX = 100;
const char	AMOEBA = '#';
const char	VISTIED = 'V';
char	petri_dish[MAX][MAX + 1];

// 위, 아래, 오른쪽, 왼쪽
// 위 + 오른쪽, 위 + 왼쪽
// 아래 + 오른쪽, 아래 + 왼쪽
int	dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int	dx[] = {0, 0, 1, -1, 1, -1, 1, -1};

void	dfs(int y, int x, int &y_size, int &x_size)
{
	if (!(0 <= y && y < y_size)
		|| !(0 <= x && x < x_size)
		|| !(petri_dish[y][x] == AMOEBA))
		return ;
	petri_dish[y][x] = VISTIED;
	for (int i = 0; i < 8; i++)
		dfs(y + dy[i], x + dx[i], y_size, x_size);
}

int	main(void)
{
	int	y, x;
	int	y_size, x_size;
	int	amoeba_cnt = 0;

	scanf(" %d %d", &y_size, &x_size);
	for (y = 0; y < y_size; y++)
		scanf(" %s", petri_dish[y]);
	for (y = 0; y < y_size; y++)
		for (x = 0; x < x_size; x++)
			if (petri_dish[y][x] == AMOEBA)
				dfs(y, x, y_size, x_size), amoeba_cnt++;
	printf("%d\n", amoeba_cnt);
	return (0);
}
