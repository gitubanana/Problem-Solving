#include <iostream>

const int MAX = 26;

int	dist[MAX][MAX];

void	init_dist(void)
{
	int	from, to;

	for (from = 0; from < MAX; from++)
		for (to = 0; to < MAX; to++)
			dist[from][to] = 1e9;
}

void	make_floyd(void)
{
	int	mid, from, to;

	for (mid = 0; mid < MAX; mid++)
		for (from = 0; from < MAX; from++)
			for (to = 0; to < MAX; to++)
				if (from != to && dist[from][to] > dist[from][mid] + dist[mid][to])
					dist[from][to] = dist[from][mid] + dist[mid][to];
}

int	main(void)
{
	char	from, to;
	int		e_cnt, test_cnt;

	init_dist();
	scanf("%d", &e_cnt);
	while (e_cnt--)
	{
		scanf(" %c is %c", &from, &to);
		dist[from - 'a'][to - 'a'] = 1;
	}
	make_floyd();
	scanf("%d", &test_cnt);
	while (test_cnt--)
	{
		scanf(" %c is %c", &from, &to);
		if (from == to || dist[from - 'a'][to - 'a'] != 1e9)
			printf("T\n");
		else
			printf("F\n");
	}
	return (0);
}
