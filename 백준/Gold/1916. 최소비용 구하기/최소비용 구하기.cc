#include <iostream>
#include <queue>
#include <list>

typedef struct
{
	int	to;
	long long	weight;
}	t_edge;

const int	MAX = 100001;
const int	INF = 1e9;

std::vector<t_edge>	map[MAX];

// 위, 아래, 오른쪽, 왼쪽
// 위 + 오른쪽, 위 + 왼쪽
// 아래 + 오른쪽, 아래 + 왼쪽
int	dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int	dx[] = {0, 0, 1, -1, 1, -1, 1, -1};

int visited[100001];
long long dist[100001];

void	dijkstra(int &start, int &v_cnt)
{
	int				cur_v, to;

	for (to = 1; to <= v_cnt; to++)
		dist[to] = INF;
	dist[start] = 0;

	while (1)
	{
		cur_v = 0;
		for(int i = 1; i <= v_cnt; i++)
			if (visited[i] == 0 && (cur_v == 0 || dist[i] < dist[cur_v]))
				cur_v = i;

		if (cur_v == 0)
			break ;

		visited[cur_v] = 1;
		for(int i = 0; i < static_cast<int>(map[cur_v].size()); i++)
		{
			int next = map[cur_v][i].to;
			long long nextDist = map[cur_v][i].weight;
			if (dist[next] > dist[cur_v] + nextDist)
				dist[next] = dist[cur_v] + nextDist;
		}
	}

	// q.push(start);
	// while (!q.empty())
	// {
	// 	cur_v = q.front(), q.pop();
	// 	for (to = 0; to < static_cast<int>(map[cur_v].size()); to++)
	// 	{
	// 		if (dist[map[cur_v][to].to] > dist[cur_v] + map[cur_v][to].weight)
	// 		{
	// 			dist[map[cur_v][to].to] = dist[cur_v] + map[cur_v][to].weight;
	// 			q.push(map[cur_v][to].to);
	// 		}
	// 	}
	// }
}

int	main(void)
{
	t_edge	edge;
	// int		*dist;
	int		start, dest;
	int		from, v_cnt, e_cnt;

	scanf(" %d %d", &v_cnt, &e_cnt);
	// dist = new int[v_cnt + 1];
	while (e_cnt--)
	{
		scanf(" %d %d %lld", &from, &edge.to, &edge.weight);
		map[from].push_back(edge);
	}
	scanf(" %d %d", &start, &dest);
	dijkstra(start, v_cnt);
	printf("%lld\n", dist[dest]);
	return (0);
}
