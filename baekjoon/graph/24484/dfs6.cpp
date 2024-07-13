#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

const int MAX_V = 1e5;

int vCnt, totalOrder;
long long depth[MAX_V + 1];
long long order[MAX_V + 1];
std::vector<int> edges[MAX_V + 1];

void    dfs(int cur, long long curDepth=0)
{
        std::vector<int> &curEdge = edges[cur];

        depth[cur] = curDepth;
        order[cur] = ++totalOrder;
        std::sort(curEdge.begin(), curEdge.end(), std::greater<int>());
        for (const int &next : curEdge)
        {
                if (order[next])
                        continue ;

                dfs(next, curDepth + 1);
        }
}

int     main(void)
{
        std::cin.tie(0)->sync_with_stdio(0);

        int eCnt, start;

        std::cin >> vCnt >> eCnt >> start;
        while (eCnt--)
        {
                int from, to;

                std::cin >> from >> to;
                edges[from].push_back(to);
                edges[to].push_back(from);
        }

        memset(depth, -1, sizeof(depth));
        dfs(start);

        long long ans = 0;
        for (int v = 1; v <= vCnt; ++v)
        {
                ans += depth[v] * order[v];
        }

        std::cout << ans << '\n';
        return (0);
}
