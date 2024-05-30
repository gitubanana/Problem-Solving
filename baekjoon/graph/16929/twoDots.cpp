#include <iostream>
#include <queue>

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 50;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int visited[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];

bool bfs(const t_pos &start)
{
    int curTime = 1;
    std::queue<t_pos> q;
    const char &color = map[start.y][start.x];

    visited[start.y][start.x] = curTime;
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            const t_pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                const t_pos next = {cur.y + dy[dir], cur.x + dx[dir]};

                if (!(0 <= next.y && next.y < ySize)
                    || !(0 <= next.x && next.x < xSize)
                    || map[next.y][next.x] != color)
                    continue ;

                int &nextVisited = visited[next.y][next.x];
                if (nextVisited == curTime)
                    return (true);

                if (nextVisited)
                    continue ;

                nextVisited = curTime;
                q.push(next);
            }
        }

        ++curTime;
    }
    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
    }

    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            if (visited[y][x])
                continue ;

            if (bfs({y, x}))
            {
                std::cout << "Yes" << '\n';
                return (0);
            }
        }
    }

    std::cout << "No" << '\n';
    return (0);
}
