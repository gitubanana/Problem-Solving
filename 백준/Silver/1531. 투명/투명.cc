#include <iostream>

typedef struct
{
	int	y, x;
}	t_pos;

const int	MAX = 101;

int	map[MAX][MAX];

int	main(void)
{
	t_pos	start;
	t_pos	end;
	int		paper_cnt, num;
	int		ans, y, x;

	scanf(" %d %d", &paper_cnt, &num);
	while (paper_cnt)
	{
		scanf(" %d %d", &start.x, &start.y);
		scanf(" %d %d", &end.x, &end.y);
		for (y = start.y; y <= end.y; ++y)
			for (x = start.x; x <= end.x; ++x)
				++map[y][x];
		--paper_cnt;
	}
	ans = 0;
	end = {100, 100};
	for (y = 1; y <= end.y; ++y)
		for (x = 1; x <= end.x; ++x)
				ans += (map[y][x] > num);
	printf("%d\n", ans);
	return (0);
}
