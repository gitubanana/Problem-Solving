#include <iostream>
#include <climits>

const int MAX_V = 101;
const int INF = 1e8;

int vCnt;
int dists[MAX_V][MAX_V];

void    floyd(void)
{
    for (int mid = 1; mid <= vCnt; ++mid)
    {
        for (int from = 1; from <= vCnt; ++from)
        {
            for (int to = 1; to <= vCnt; ++to)
            {
                dists[from][to] = std::min(
                    dists[from][to],
                    dists[from][mid] + dists[mid][to]
                );
            }
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    for (int v = 1; v <= vCnt; ++v)
    {
        for (int v2 = 1; v2 <= vCnt; ++v2)
        {
            if (v == v2)
                continue ;

            dists[v][v2] = INF;
        }
    }
    while (eCnt--)
    {
        int from, to;

        std::cin >> from >> to;
        dists[from][to] = dists[to][from] = 1;
    }

    floyd();

    int minV, maxV;
    int minCost = INT_MAX;
    for (int min = 1; min < vCnt; ++min)
    {
        for (int max = min + 1; max <= vCnt; ++max)
        {
            int cmpCost = 0;

            for (int v = 1; v <= vCnt; ++v)
            {
                cmpCost += std::min(
                    dists[min][v],
                    dists[max][v]
                ) * 2;
            }

            if (minCost > cmpCost)
            {
                minCost = cmpCost;
                minV = min;
                maxV = max;
            }
        }
    }

    std::cout << minV << ' ' << maxV << ' ' << minCost << '\n';
    return (0);
}
