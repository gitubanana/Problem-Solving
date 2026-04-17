#include <iostream>
#include <queue>

typedef struct s_edge t_edge;

struct s_edge
{
    int to;
    int weight;
    
    int operator<(const t_edge &b) const
    {
        return (weight < b.weight);
    }
};

const int   MAX = 5001;
const int   INF = 1e9;

std::vector<t_edge> map[MAX];

void    swap(int *a, int *b)
{
    int tmp = *a;
    
    *a = *b;
    *b = tmp;
}

void    push_pq(std::priority_queue<t_edge> &pq, int to, int weight)
{
    t_edge  edge;
    
    edge.to = to;
    edge.weight = weight;
    pq.push(edge);
}

void    dijkstra(int *&dist, int &v_cnt, int &start, int &dest)
{
    std::priority_queue<t_edge>   pq;
    int                         i, cur_v, cur_dist;
    int                         next_v, next_dist;
    
    for (i = 1; i <= v_cnt; i++)
        dist[i] = INF;
    dist[start] = 0;
    push_pq(pq, start, 0);
    while (!pq.empty())
    {
        cur_v = pq.top().to;
        cur_dist = -pq.top().weight, pq.pop();
        if (dist[cur_v] != cur_dist)
            continue ;
        for (i = 0; i < map[cur_v].size(); i++)
        {
            next_v = map[cur_v][i].to;
            next_dist = map[cur_v][i].weight + cur_dist;
            if (dist[next_v] > next_dist)
            {
                dist[next_v] = next_dist;
                push_pq(pq, next_v, -next_dist);
            }
        }
    }
}

int main()
{
    t_edge  edge;
    int     start, dest;
    int     v_cnt, e_cnt, from;
    int     *dist;

    scanf(" %d %d", &v_cnt, &e_cnt);
    dist = new int[v_cnt + 1];
    while (e_cnt--)
    {
        scanf(" %d %d %d", &from, &edge.to, &edge.weight);
        map[from].push_back(edge);
        swap(&from, &edge.to);
        map[from].push_back(edge);
    }
    scanf(" %d %d", &start, &dest);
    dijkstra(dist, v_cnt, start, dest);
    printf("%d\n", dist[dest]);
    delete[] dist;
    return 0;
}