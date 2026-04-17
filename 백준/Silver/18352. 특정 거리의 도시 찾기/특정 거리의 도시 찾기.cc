#include <iostream>
#include <queue>
#include <list>

const int	MAX = 300001;
const int	INF = 1e9;

std::vector<int>	map[MAX];

void	dijkstra(int *&dist, int &v_cnt, int &start, int &to)
{
	std::queue<int>	q;
	int				cur_v;

	for (to = 1; to <= v_cnt; to++)
		dist[to] = INF;
	dist[start] = 0;
	q.push(start);
	while (!q.empty())
	{
		cur_v = q.front(), q.pop();
		for (to = 0; to < static_cast<int>(map[cur_v].size()); to++)
		{
			if (dist[map[cur_v][to]] >= dist[cur_v] + 1)
			{
				dist[map[cur_v][to]] = dist[cur_v] + 1;
				q.push(map[cur_v][to]);
			}
		}
	}
}

int	main(void)
{
	int	*dist;
	int	found;
	int	from, to;
	int	v_cnt, e_cnt;
	int	start, want_dist;

	scanf(" %d %d %d %d", &v_cnt, &e_cnt, &want_dist, &start);
	dist = new int[v_cnt + 1];
	while (e_cnt--)
	{
		scanf(" %d %d", &from, &to);
		map[from].push_back(to);
	}
	dijkstra(dist, v_cnt, start, to);
	found = 0;
	for (to = 1; to <= v_cnt; to++)
		if (dist[to] == want_dist)
			printf("%d\n", to), found = 1;
	if (!found)
		printf("-1\n");
	delete[] dist;
	return (0);
}
