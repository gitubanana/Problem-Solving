#include <list>
#include <cstring>
#include <iostream>

const int	MAX = 100;
const int	IS_LINKED = 1;

int	matrix[MAX][MAX];
int	visited[MAX];
int	can_go;

void	find_can_go(int start, int &dest, int &v_cnt)
{
	for (int i = 0; i < v_cnt; i++)
	{
		if (matrix[start][i] == IS_LINKED && visited[i] == 0)
		{
			if (i == dest)
			{
				can_go = 1;
				return ;
			}
			visited[i] = 1;
			find_can_go(i, dest, v_cnt);
		}
	}
}

int	main(void)
{
	int	i, j;
	int	v_cnt, is_linked;

	std::cin >> v_cnt;
	for (i = 0; i < v_cnt; i++)
	{
		for (j = 0; j < v_cnt; j++)
		{
			std::cin >> is_linked;
			matrix[i][j] = is_linked;
		}
	}
	for (i = 0; i < v_cnt; i++)
	{
		for (j = 0; j < v_cnt; j++)
		{
			can_go = 0;
			memset(visited, 0, sizeof(visited));
			find_can_go(i, j, v_cnt);
			std::cout << can_go << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}