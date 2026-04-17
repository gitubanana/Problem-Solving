#include <stdio.h>
#include <stdint.h>
#define MAX 51

enum e_true_false
{
	NO = 0,
	YES
};

char	map[MAX][MAX];
int		visited[MAX][MAX];
int		row_cnt, col_cnt;

void	dfs(int cur_row, int cur_col)
{	
	visited[cur_row][cur_col] = YES;

	if (map[cur_row][cur_col] == '-' && map[cur_row][cur_col + 1] == '-')
		dfs(cur_row, cur_col + 1);
	
	if (map[cur_row][cur_col] == '|' && map[cur_row + 1][cur_col] == '|')
		dfs(cur_row + 1, cur_col);
}

int main(void)
{
	int	i, j;
	int	cnt = 0;

	scanf("%d %d", &row_cnt, &col_cnt);
	for (i = 0; i < row_cnt; i++)
		scanf("%s", map[i]);
	for (i = 0; i < row_cnt; i++)
	{
		for (j = 0; j < col_cnt; j++)
		{
			if (visited[i][j] == NO)
			{
				dfs(i, j);
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	return (0);
}