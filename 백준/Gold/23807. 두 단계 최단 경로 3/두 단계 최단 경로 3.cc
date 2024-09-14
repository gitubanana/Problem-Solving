#include <iostream>
#include <vector>
#include <queue>

struct t_edge
{
    int v;
    int weight;
};

struct t_elem
{
    int v;
    int64_t weight;

    inline bool operator<(const t_elem &other) const
    {
        return (this->weight > other.weight);
    }
};

const int MAX_V = 100'001;
const int PASS_CNT = 3;
const int MAX_PASS = 100;
const int64_t INF = 1e12 + 1;

int vCnt;
int size;
int start, end;
int pass[PASS_CNT];
int shouldPass[MAX_PASS];
bool visited[MAX_PASS];
int64_t ans = INF;
int64_t dists[MAX_PASS][MAX_V];
std::vector<t_edge> edges[MAX_V];

void    dijkstra(int start, int64_t dists[MAX_V])
{
    std::priority_queue<t_elem> pq;

    for (int v = 1; v <= vCnt; ++v)
    {
        dists[v] = INF;
    } 

    dists[start] = 0;
    pq.push({start, 0});
    while (!pq.empty())
    {
        const t_elem cur = pq.top();
        const int64_t &curDist = dists[cur.v];
        pq.pop();

        if (curDist != cur.weight)
            continue ;

        for (const t_edge &next : edges[cur.v])
        {
            int64_t &cmpDist = dists[next.v];
            int64_t nextDist = curDist + next.weight;
            if (cmpDist <= nextDist)
                continue ;

            cmpDist = nextDist;
            pq.push({next.v, nextDist});
        }
    }
}

void    backTracking(int depth=0)
{
    if (depth == PASS_CNT)
    {
        const int &aIdx = pass[0];
        const int &bIdx = pass[1];
        const int &cIdx = pass[2];
        const int &A = shouldPass[aIdx];
        const int &B = shouldPass[bIdx];
        const int &C = shouldPass[cIdx];

        ans = std::min(
            ans,
            dists[aIdx][start] + dists[aIdx][B]
            + dists[cIdx][B] + dists[cIdx][end]
        );
        return ;
    }

    for (int i = 0; i < size; ++i)
    {
        if (visited[i])
            continue ;

        pass[depth] = i;
        visited[i] = true;
        backTracking(depth + 1);
        visited[i] = false;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    while (eCnt--)
    {
        int from, to, weight;

        std::cin >> from >> to >> weight;
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }

    std::cin >> start >> end >> size;
    for (int i = 0; i < size; ++i)
    {
        int &cur = shouldPass[i];

        std::cin >> cur;
        dijkstra(cur, dists[i]);
    }

    backTracking();
    std::cout << (ans == INF ? -1 : ans) << '\n';
    return (0);
}
