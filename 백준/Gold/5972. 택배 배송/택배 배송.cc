#include <iostream>
#include <queue>

typedef struct s_edge	t_edge;

typedef struct s_edge
{
	int	to;
	int	weight;

	int	operator<(const t_edge &b) const
	{
		return (weight < b.weight);
	}
}	t_edge;


const int	MAX = 50001;
const int	INF = 1e9;

std::vector<t_edge>	map[MAX];

void	swap(int &a, int &b)
{
	int	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

void	push_pq(std::priority_queue<t_edge>	&pq, int to, int weight)
{
	t_edge	edge;

	edge.to = to;
	edge.weight = weight;
	pq.push(edge);
}

void	dijkstra(int &v_cnt, int start, int dest)
{
	std::priority_queue<t_edge>	pq;
	int							*dist, to;
	int							cur_v, cur_dist;
	int							next_v, next_dist;

	dist = new int[v_cnt + 1];
	for (to = 1; to <= v_cnt; to++)
		dist[to] = INF;
	dist[start] = 0;
	push_pq(pq, start, 0);
	while (!pq.empty())
	{
		cur_v = pq.top().to;
		cur_dist = -pq.top().weight, pq.pop();
		if (dist[cur_v] != cur_dist)
			continue ;
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
	printf("%d\n", dist[dest]);
	delete[] dist;
}

int	main(void)
{
	t_edge	edge;
	int		from, dest;
	int		v_cnt, e_cnt;

	scanf(" %d %d", &v_cnt, &e_cnt);
	dest = v_cnt;
	while (e_cnt--)
	{
		scanf(" %d %d %d", &from, &edge.to, &edge.weight);
		map[from].push_back(edge);
		swap(from, edge.to);
		map[from].push_back(edge);
	}
	dijkstra(v_cnt, 1, dest);
	return (0);
}
