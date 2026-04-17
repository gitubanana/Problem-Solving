#include <iostream>

const int	MAX = 101;

int	dist[MAX][MAX];

void	init_dist(int &v_cnt)
{
	int	from, to;

	for (from = 1; from <= v_cnt; from++)
		for (to = 1; to <= v_cnt; to++)
			dist[from][to] = 1e9;
}

void	make_floyd(int &v_cnt)
{
	int	from, to, mid;

	for (mid = 1; mid <= v_cnt; mid++)
		for (from = 1; from <= v_cnt; from++)
			for (to = 1; to <= v_cnt; to++)
				if (from != to && dist[from][to] > dist[from][mid] + dist[mid][to])
					dist[from][to] = dist[from][mid] + dist[mid][to];
}

void	print_ans(int &v_cnt)
{
	int	*kevin_bacon;
	int	from, to, min_bacon;

	kevin_bacon = new int[v_cnt + 1];
	for (from = 1; from <= v_cnt; from++)
		kevin_bacon[from] = 0;

	for (from = 1; from <= v_cnt; from++)
		for (to = 1; to <= v_cnt; to++)
			if (dist[from][to] != 1e9)
				kevin_bacon[from] += dist[from][to];

	min_bacon = kevin_bacon[1];
	for (from = 2; from <= v_cnt; from++)
		if (min_bacon > kevin_bacon[from])
			min_bacon = kevin_bacon[from];

	for (from = 1; from <= v_cnt; from++)
		if (min_bacon == kevin_bacon[from])
			break ;

	printf("%d\n", from);
	delete[] kevin_bacon;
}

int	main(void)
{
	int	from, to;
	int	v_cnt, e_cnt;

	scanf(" %d %d", &v_cnt, &e_cnt);
	init_dist(v_cnt);
	while (e_cnt--)
	{
		scanf(" %d %d", &from, &to);
		dist[from][to] = 1;
		dist[to][from] = 1;
	}
	make_floyd(v_cnt);
	print_ans(v_cnt);
	return (0);
}