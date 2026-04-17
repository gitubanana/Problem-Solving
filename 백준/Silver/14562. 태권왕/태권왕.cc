#include <iostream>
#include <cstring>
#include <queue>

struct t_pos
{
    int cur;
    int end;
};

const int MAX = 1000;

int vCnt;
bool visited[MAX][MAX];

int bfs(const t_pos &start)
{
    static int ds[] = {-1, 1};
    static int de[] = {3, 0};
    static const int dirSize = sizeof(ds) / sizeof(ds[0]);

    int kick = 1;
    std::queue<t_pos> q;

    memset(visited, false, sizeof(visited));
    visited[start.cur][start.end] = true;
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            const t_pos cur = q.front();
            q.pop();

            ds[0] = cur.cur;
            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {
                    cur.cur + ds[dir],
                    cur.end + de[dir]
                };

                if (cur.cur > cur.end)
                    continue ;

                if (next.cur == next.end)
                    return (kick);

                if (visited[next.cur][next.end])
                    continue ;

                visited[next.cur][next.end] = true;
                q.push(next);
            }
        }

        ++kick;
    }

    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        t_pos start;

        std::cin >> start.cur >> start.end;
        std::cout << bfs(start) << '\n';
    }
    return (0);
}
