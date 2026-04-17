#include <iostream>
#include <limits.h>

const int	MAX = 51;

int	dist[MAX][MAX];

void	init_dist(int &v_cnt, int &from, int &to)
{
	for (from = 1; from <= v_cnt; from++)
		for (to = 1; to <= v_cnt; to++)
			dist[from][to] = 1e9;
}

void	make_floyd(int &v_cnt, int &from, int &to)
{
	int	mid;

	for (mid = 1; mid <= v_cnt; mid++)
		for (from = 1; from <= v_cnt; from++)
			for (to = 1; to <= v_cnt; to++)
				if (from != to && dist[from][to] > dist[from][mid] + dist[mid][to])
					dist[from][to] = dist[from][mid] + dist[mid][to];
}

void	print_ans(int *&point, int &v_cnt, int &from, int &to)
{
	int	max_point;
	int	boss_point = INT_MAX, boss_cnt = 0;

	for (from = 1; from <= v_cnt; from++)
	{
		if (from != 1)
			max_point = dist[from][1];
		else
			max_point = dist[from][2];
		for (to = 2; to <= v_cnt; to++)
			if (from != to && max_point < dist[from][to])
				max_point = dist[from][to];
		point[from] = max_point;
		if (boss_point > point[from])
			boss_point = point[from];
	}
	for (from = 1; from <= v_cnt; from++)
		if (boss_point == point[from])
			boss_cnt++;
	printf("%d %d\n", boss_point, boss_cnt);
	for (from = 1; from <= v_cnt; from++)
		if (boss_point == point[from])
			printf("%d ", from);
}

int	main(void)
{
	int	*point;
	int	v_cnt, from, to;

	scanf(" %d", &v_cnt);
	point = new int[v_cnt + 1];
	init_dist(v_cnt, from, to);
	while (1)
	{
		scanf(" %d %d", &from, &to);
		if (from == -1 && to == -1)
			break ;
		dist[from][to] = 1, dist[to][from] = 1;
	}
	make_floyd(v_cnt, from, to);
	print_ans(point, v_cnt, from, to);
	delete[] point;
	return (0);
}
