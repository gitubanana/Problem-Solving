#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 8

int	get_change_cnt(char board[50][51], int x, int y, char start_ch)
{
	int		ret;
	int		save_x, save_y;
	int		x_limit, y_limit;

	ret = 0;
	save_x = x; save_y = y;
	x_limit = x + SIZE; y_limit = y + SIZE;
	for (; x < x_limit; x++)
	{
		for (y = save_y; y < y_limit; y++)
		{
			if ((x - save_x) % 2 == 0)
			{
				if (((y - save_y) % 2 == 0 && board[x][y] != start_ch)
					|| ((y - save_y) % 2 && board[x][y] == start_ch))
					ret++;
			}
			else
			{
				if (((y - save_y) % 2 && board[x][y] != start_ch)
					|| ((y - save_y) % 2 == 0 && board[x][y] == start_ch))
					ret++;
			}
		}
	}
	return (ret);
}

int main(void)
{
	int		x, y;
	int		min, tmp;
	int		row_cnt, col_cnt;
	char	board[50][51];

	scanf("%d %d", &row_cnt, &col_cnt);
	for (x = 0; x < row_cnt; x++)
		scanf("%s", board[x]);
	min = INT_MAX;
	row_cnt -= SIZE;
	col_cnt -= SIZE;
	for (x = 0; x <= row_cnt; x++)
	{
		for (y = 0; y <= col_cnt; y++)
		{
			tmp = get_change_cnt(board, x, y, 'W');
			if (min > tmp)
				min = tmp;
			tmp = get_change_cnt(board, x, y, 'B');
			if (min > tmp)
				min = tmp;
		}
	}	
	printf("%d", min);
	return (0);
}