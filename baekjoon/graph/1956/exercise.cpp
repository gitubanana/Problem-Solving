#include <iostream>

const int MAX = 401;
const int INF = 1e8;

int vCnt;
int dists[MAX][MAX];

void    initDists(void)
{
    for (int v = 1; v <= vCnt; ++v)
    {
        for (int v2 = 1; v2 <= vCnt; ++v2)
        {
            if (v == v2)
                continue ;

            dists[v][v2] = INF;
        }
    }
}

void    floyd(void)
{
    for (int mid = 1; mid <= vCnt; ++mid)
    {
        for (int from = 1; from <= vCnt; ++from)
        {
            for (int to = 1; to <= vCnt; ++to)
            {
                int cmpDist = dists[from][mid] + dists[mid][to];

                if (dists[from][to] > cmpDist)
                {
                    dists[from][to] = cmpDist;
                }
            }
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;
    int from, to;

    std::cin >> vCnt >> eCnt;
    initDists();
    while (eCnt)
    {
        std::cin >> from >> to >> dists[from][to];
        --eCnt;
    }

    floyd();

    int ans = INF;
    for (int from = 1; from <= vCnt; ++from)
    {
        for (int to = 1; to <= vCnt; ++to)
        {
            if (from == to)
                continue ;

            if (dists[from][to] == INF || dists[to][from] == INF)
                continue ;

            ans = std::min(ans, dists[from][to] + dists[to][from]);
        }
    }
    std::cout << (ans == INF ? -1 : ans) << '\n';
    return (0);
}
