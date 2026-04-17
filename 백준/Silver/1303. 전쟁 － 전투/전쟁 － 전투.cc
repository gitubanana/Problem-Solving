#include <math.h>
#include <cstring>
#include <iostream>

const int	MAX = 100;
const char	VISITED = 'V';

int		our, opp;
int		x_size, y_size;
char	map[MAX][MAX + 1];
//위, 아래, 오른쪽, 왼쪽
int	dy[] = {-1, 1, 0, 0};
int	dx[] = {0, 0, 1, -1};

void	dfs(int y, int x, int &tmp, char can_go)
{
	if (!(0 <= y && y < y_size) || !(0 <= x && x < x_size)
		|| (map[y][x] == VISITED) || (map[y][x] != can_go))
		return ;
	tmp++;
	map[y][x] = VISITED;
	for (int i = 0; i < 4; i++)
		dfs(y + dy[i], x + dx[i], tmp, can_go);
}

int	main(void)
{
	int	y, x;
	int	our_tmp, opp_tmp;

	std::cin >> x_size >> y_size;
	for (y = 0; y < y_size; y++)
		std::cin >> map[y];
	for (y = 0; y < y_size; y++)
	{
		for (x = 0; x < x_size; x++)
		{
			our_tmp = opp_tmp = 0;
			dfs(y, x, our_tmp, 'W');
			our += pow(our_tmp, 2);
			dfs(y, x, opp_tmp, 'B');
			opp += pow(opp_tmp, 2);
		}
	}
	std::cout << our << " " << opp;
	return (0);
}