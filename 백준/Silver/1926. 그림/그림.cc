#include <math.h>
#include <cstring>
#include <iostream>

const int	MAX = 500;

int	y_size, x_size;
char sketch[MAX][MAX];

//위, 아래, 오른쪽, 왼쪽
int	dy[] = {-1, 1, 0, 0};
int	dx[] = {0, 0, 1, -1};

void	dfs(int y, int x, int &tmp)
{
	++tmp;
	sketch[y][x] = '0';
	for (int i = 0; i < 4; i++)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (!(0 <= nextY && nextY < y_size)
            || !(0 <= nextX && nextX < x_size)
            || sketch[nextY][nextX] == '0')
            continue ;

        dfs(nextY, nextX, tmp);
    }
}

int	main(void)
{
	int	y, x;
	int	cnt = 0, max = 0, tmp;

	std::cin >> y_size >> x_size;
	for (y = 0; y < y_size; ++y)
    {
		for (x = 0; x < x_size; ++x)
        {
            std::cin >> sketch[y][x];
        }
    }
	for (y = 0; y < y_size; ++y)
	{
		for (x = 0; x < x_size; ++x)
		{
			if (sketch[y][x] == '1')
			{
				tmp = 0;
				dfs(y, x, tmp), ++cnt;
				max = std::max(max, tmp);
			}
		}
	}
	std::cout << cnt << std::endl << max;
	return (0);
}