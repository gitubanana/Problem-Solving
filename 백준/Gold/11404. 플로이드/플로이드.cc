#include <iostream>

const int	MAX = 101;

int	dist[MAX][MAX];

void	print_dist(int &v_cnt)
{
	int	from, to;

	for (from = 1; from <= v_cnt; from++)
	{
		for (to = 1; to <= v_cnt; to++)
		{
			if (dist[from][to] == 1e9)
				printf("0 ");
			else
				printf("%d ", dist[from][to]);
		}
		printf("\n");
	}
}

void	init_dist(int &v_cnt, int &from, int &to)
{
	for (from = 1; from <= v_cnt; from++)
		for (to = 1; to <= v_cnt; to++)
			dist[from][to] = 1e9;
}

void	make_floyd(int &v_cnt, int &mid, int &from, int &to)
{
	for (mid = 1; mid <= v_cnt; mid++)
		for (from = 1; from <= v_cnt; from++)
			for (to = 1; to <= v_cnt; to++)
				if (from != to && dist[from][to] > dist[from][mid] + dist[mid][to])
					dist[from][to] = dist[from][mid] + dist[mid][to];
}

int	main(void)
{
	int	v_cnt, e_cnt;
	int	from, mid, to, weight;

	std::cin >> v_cnt >> e_cnt;
	init_dist(v_cnt, from, to);
	while (e_cnt--)
	{
		std::cin >> from >> to >> weight;
		if (dist[from][to] > weight)
			dist[from][to] = weight;
	}
	make_floyd(v_cnt, mid, from, to);
	print_dist(v_cnt);
	return (0);
}
