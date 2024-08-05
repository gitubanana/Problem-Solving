#include <iostream>
#include <queue>

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 500;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize, heightDiff;
int height[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
std::queue<t_pos> toClean;

void    bfs(const t_pos &start)
{
    std::queue<t_pos> q;

    visited[start.y][start.x] = true;
    q.push(start);
    while (!q.empty())
    {
        const t_pos cur = q.front();
        const int &curHeight = height[cur.y][cur.x];
        q.pop();

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir]
            };

            if (!(0 <= next.y && next.y < ySize)
                || !(0 <= next.x && next.x < xSize)
                || visited[next.y][next.x])
                continue ;

            if (std::abs(curHeight - height[next.y][next.x]) > heightDiff)
            {
                toClean.push(next);
                continue ;
            }

            visited[next.y][next.x] = true;
            q.push(next);
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize >> heightDiff;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> height[y][x];
        }
    }

    int ans = 0;

    toClean.push({0, 0});
    while (!toClean.empty())
    {
        const t_pos start = toClean.front();
        toClean.pop();

        if (visited[start.y][start.x])
            continue ;

        bfs(start);
        ++ans;
    }

    std::cout << ans << '\n';
    return (0);
}
