#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 100;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int map[MAX_SIZE][MAX_SIZE];
int height[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

void bfs(const t_pos &start, int poolHeight)
{
    static std::vector<t_pos> poolPos;

    bool isOut = false;
    int water = poolHeight - map[start.y][start.x];
    std::queue<t_pos> q;

    poolPos.clear();
    poolPos.push_back(start);
    visited[start.y][start.x] = true;
    q.push(start);
    while (!q.empty())
    {
        const t_pos cur = q.front();
        q.pop();

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir]
            };

            if (!(0 <= next.y && next.y < ySize)
                || !(0 <= next.x && next.x < xSize))
            {
                isOut = true;
                continue ;
            }

            int &nextHeight = map[next.y][next.x];
            bool &nextVisited = visited[next.y][next.x];
            if (nextVisited || nextHeight >= poolHeight)
                continue ;

            poolPos.push_back(next);
            nextVisited = true;
            q.push(next);
        }
    }

    if (isOut)
        return ;

    for (const t_pos &pos : poolPos)
    {
        int &curHeight = height[pos.y][pos.x];

        curHeight = std::max(curHeight, poolHeight - map[pos.y][pos.x]);
    }
}

void countPoolWater(int poolHeight)
{
    memset(visited, false, sizeof(visited));
    for (int y = 1; y < ySize - 1; ++y)
    {
        for (int x = 1; x < xSize - 1; ++x)
        {
            if (visited[y][x] || map[y][x] >= poolHeight)
                continue ;

            bfs({y, x}, poolHeight);
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int minHeight = INT_MAX;
    int maxHeight = INT_MIN;

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            int &curHeight = map[y][x];

            std::cin >> curHeight;
            minHeight = std::min(minHeight, curHeight);
            maxHeight = std::max(maxHeight, curHeight);
        }
    }

    for (int height = minHeight; height <= maxHeight; ++height)
    {
        countPoolWater(height);
    }

    int ans = 0;
    for (int y = 1; y < ySize - 1; ++y)
    {
        for (int x = 1; x < xSize - 1; ++x)
        {
            ans += height[y][x];
        }
    }

    std::cout << ans << '\n';
    return (0);
}
