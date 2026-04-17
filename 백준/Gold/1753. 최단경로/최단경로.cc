#include <iostream>
#include <queue>

typedef struct s_edge	t_edge;

typedef struct s_edge 
{
	int	to;
	int	weight;

	bool operator<(const t_edge &b) const
	{
		return weight < b.weight;
	}
}	t_edge;

const int	MAX = 20001;
const int	INF = 1e9;

std::vector<t_edge>	map[MAX];
int					dist[MAX];

void	push_pq(std::priority_queue<t_edge> &pq, int to, int dist)
{
	t_edge	edge;

	edge.to = to;
	edge.weight = dist;
	pq.push(edge);
}

void	dijkstra(int &start, int &v_cnt)
{
	std::priority_queue<t_edge>	pq;
	int							cur_v, cur_dist, to;
	int							next_v, next_dist;

	for (to = 1; to <= v_cnt; to++)
		dist[to] = INF;
	dist[start] = 0;
	push_pq(pq, start, 0);
	while (!pq.empty())
	{
		cur_v = pq.top().to;
		cur_dist = -pq.top().weight, pq.pop();


		if (cur_dist != dist[cur_v])
			continue;
		for (to = 0; to < static_cast<int>(map[cur_v].size()); to++)
		{
			next_v = map[cur_v][to].to;
			next_dist = cur_dist + map[cur_v][to].weight;
			if (dist[next_v] > next_dist)
			{
				dist[next_v] = next_dist;
				push_pq(pq, next_v, -next_dist);
			}
		}
	}
}

int	main(void)
{
	t_edge	edge;
	int		start;
	int		from, v_cnt, e_cnt;

	scanf(" %d %d %d", &v_cnt, &e_cnt, &start);
	while (e_cnt--)
	{
		scanf(" %d %d %d", &from, &edge.to, &edge.weight);
		map[from].push_back(edge);
	}
	dijkstra(start, v_cnt);
	for (from = 1; from <= v_cnt; from++)
	{
		if (dist[from] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[from]);
	}
	return (0);
}
