#include <stdio.h>
#define ROW_CNT 8

int	get_horse_cnt(char *row, int cur_row)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (row[i])
	{
		if (i % 2 == cur_row % 2 && row[i] == 'F')
			ret++;
		i++;
	}
	return (ret);
}

int main(void)
{
	char	row[ROW_CNT + 1];
	int		ans;
	int		cur_row;

	ans = 0;
	cur_row = 0;
	while (cur_row < ROW_CNT)
	{
		scanf("%s", row);
		ans += get_horse_cnt(row, cur_row);
		cur_row++;
	}
	printf("%d", ans);
	return (0);
}