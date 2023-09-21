#include <stdio.h>

int	row, col;
char	str[100][101];

void	scan_str();
void	count_grass(int *p_cnt);
void	dfs(int i, int j);

int	main(void)
{
	int	cnt;

	cnt = 0;
	scanf("%d %d", &row, &col);
	scan_str();
	count_grass(&cnt);
	printf("%d", cnt);
	return (0);
}

void	scan_str()
{
	int	i;

	for (i = 0; i < row; i++)
		scanf("%s", str[i]);
}

void	count_grass(int *p_cnt)
{
	int	i, j;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (str[i][j] == '#')
			{
				(*p_cnt)++;
				dfs(i, j);
			}
		}
	}
}

void	dfs(int i, int j)
{
	str[i][j] = '.';

	//up
	if (i - 1 >= 0 && str[i - 1][j] == '#')
		dfs(i - 1, j);

	//down
	if (i + 1 <= row - 1 && str[i + 1][j] == '#')
		dfs(i + 1, j);

	//right
	if (j + 1 <= col - 1 && str[i][j + 1] == '#')
		dfs(i, j + 1);

	//left
	if (j - 1 >= 0 && str[i][j - 1] == '#')
		dfs(i, j - 1);
}

