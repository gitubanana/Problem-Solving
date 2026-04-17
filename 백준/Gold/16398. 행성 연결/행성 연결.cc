#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

typedef struct s_edge
{
	int	to;
	int	weight;

    bool	operator<(const struct s_edge &b) const
    {
    	return (this->weight > b.weight);
    }
}	t_edge;

const int	MAX = 1000;

int map[MAX][MAX];
int visited[MAX];

void    prim(int add_v, int v_cnt)
{
    int i, add_cnt;
    long long total_weight;
    t_edge  to_link;
    std::priority_queue<t_edge> pq;

    total_weight = add_cnt = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        to_link = pq.top(), pq.pop();
        if (visited[to_link.to] == 0)
        {
            ++add_cnt;
            add_v = to_link.to;
            visited[add_v] = 1;
            total_weight += to_link.weight;
            for (i = 0; i < v_cnt; ++i)
            {
                if (map[add_v][i] != 0 && visited[i] == 0)
                    pq.push({i, map[add_v][i]});
            }
        }
        if (add_cnt == v_cnt)
            break ;
    }
    printf("%ld\n", total_weight);
}

int	main(void)
{
	int		y, x;
	int		v_cnt;

	scanf(" %d", &v_cnt);
	for (y = 0; y < v_cnt; ++y)
	    for (x = 0; x < v_cnt; ++x)
	        scanf(" %d", &map[y][x]);
	prim(0, v_cnt);
	return (0);
}
