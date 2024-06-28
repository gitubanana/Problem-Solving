#include <iostream>
#include <queue>
#include <unordered_map>

const int64_t END = 1;

int64_t bfs(int64_t start)
{
    static const int64_t dx[] = {3, 2, 1};
    static const int dSize = sizeof(dx) / sizeof(dx[0]);

    if (start == END)
        return (0);

    std::queue<int64_t> q;
    std::unordered_map<int64_t, int64_t> umap;

    umap.insert({start, 0});
    q.push(start);
    while (!q.empty())
    {
        const int64_t cur = q.front();
        const int64_t &curCnt = umap[cur];
        q.pop();

        for (const int64_t &dd : dx)
        {
            int64_t next = cur / dd;
            if (next * dd != cur)
                continue ;

            next -= (dd == 1);
            if (umap.find(next) != umap.end())
                continue ;

            if (next == END)
                return (curCnt + 1);

            umap.insert({next, curCnt + 1});
            q.push(next);
        }
    }

    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int64_t start;

    std::cin >> start;
    std::cout << bfs(start) << '\n';
    return (0);
}
