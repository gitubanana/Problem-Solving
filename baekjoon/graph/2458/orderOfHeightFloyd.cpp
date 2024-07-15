#include <iostream>
#include <cstring>
#include <unordered_set>

const int MAX_V = 500 + 1;
const int INF = 1e9;

int vCnt;
int dists[MAX_V][MAX_V];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    for (int from = 1; from <= vCnt; ++from)
    {
        for (int to = 1; to <= vCnt; ++to)
        {
            if (from == to)
                continue ;

            dists[from][to] = INF;
        }
    }
    while (eCnt--)
    {
        int from, to;

        std::cin >> from >> to;
        dists[from][to] = 1;
    }

    for (int mid = 1; mid <= vCnt; ++mid)
    {
        for (int from = 1; from <= vCnt; ++from)
        {
            for (int to = 1; to <= vCnt; ++to)
            {
                int &cmpDist = dists[from][to];
                int nextDist = dists[from][mid] + dists[mid][to];

                if (cmpDist > nextDist)
                {
                    cmpDist = nextDist;
                }
            }
        }
    }

    int ans = vCnt;
    for (int from = 1; from <= vCnt; ++from)
    {
        for (int to = 1; to <= vCnt; ++to)
        {
            if (dists[from][to] == INF && dists[to][from] == INF)
            {
                --ans;
                break ;
            }
        }
    }

    std::cout << ans << '\n';
    return (0);
}
