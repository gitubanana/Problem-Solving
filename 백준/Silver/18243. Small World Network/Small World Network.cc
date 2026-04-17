#include <iostream>

const int	MAX = 101;

int	dist[MAX][MAX];

void	init_dist(int &v_cnt, int &from, int &to)
{
	for (from = 1; from <= v_cnt; from++)
		for (to = 1; to <= v_cnt; to++)
			dist[from][to] = 1e9;
}

int	main(void)
{
	int	v_cnt, e_cnt;
	int	mid, from, to;

	std::cin >> v_cnt >> e_cnt;
	init_dist(v_cnt, from, to);
	while (e_cnt--)
	{
		std::cin >> from >> to;
		dist[from][to] = 1;
		dist[to][from] = 1;
	}
	for (mid = 1; mid <= v_cnt; mid++)
		for (from = 1; from <= v_cnt; from++)
			for (to = 1; to <= v_cnt; to++)
				if (from != to && dist[from][to] > dist[from][mid] + dist[mid][to])
					dist[from][to] = dist[from][mid] + dist[mid][to];
	for (from = 1; from <= v_cnt; from++)
		for (to = 1; to <= v_cnt; to++)
			if (from != to && dist[from][to] > 6)
				std::cout << "Big World!", exit(0);
	std::cout << "Small World!";
	return (0);
}
