#include <iostream>
#include <climits>

const int V_MAX = 801;
const int INF = 1e7;

int vCnt;
int dists[V_MAX][V_MAX];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;
    int from, to;
    int stops[2];

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
        std::cin >> from >> to >> dists[from][to];
        dists[to][from] = dists[from][to];
    }
    for (int i = 0; i < 2; ++i)
    {
        std::cin >> stops[i];
    }

    for (int mid = 1; mid <= vCnt; ++mid)
    {
        for (int start = 1; start <= vCnt; ++start)
        {
            for (int end = 1; end <= vCnt; ++end)
            {
                dists[start][end] = std::min(
                    dists[start][end],
                    dists[start][mid] + dists[mid][end]
                );
            }
        }
    }

    int ans = INF;
    const int start = 1;
    const int end = vCnt;

    for (int i = 0; i < 2; ++i)
    {
        ans = std::min(
            ans,
            dists[start][stops[i]]
                + dists[stops[i]][stops[(i + 1) % 2]]
                + dists[stops[(i + 1) % 2]][end]
        );
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
    return (0);
}
