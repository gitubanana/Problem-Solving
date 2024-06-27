#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

enum e_space
{
    EMPTY = '0',
    WALL = '1',
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 1000;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int checked;
int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int    bfs(std::queue<t_pos> &q, std::vector<t_pos> &wall)
{
    int cnt = 0;

    while (!q.empty())
    {
        const t_pos cur = q.front();
        q.pop();

        if (map[cur.y][cur.x] == EMPTY)
        {
            ++cnt;
            ++checked;
        }

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

            visited[next.y][next.x] = true;

            char &nextSpace = map[next.y][next.x];
            if (nextSpace == WALL)
            {
                wall.push_back(next);
            }
            else
            {
                q.push(next);
            }
        }
    }
    return (cnt);
}

void    findSecurityLevel(int emptyCnt)
{
    std::queue<t_pos> q;
    std::vector<t_pos> wall;

    checked = 0;
    memset(visited, false, sizeof(visited));
    for (int y = 0; y < ySize; ++y)
    {
        int step = (y == 0 || y == ySize - 1 ? 1 : xSize - 1);

        for (int x = 0; x < xSize; x += step)
        {
            visited[y][x] = true;

            if (map[y][x] == WALL)
            {
                wall.push_back({y, x});
            }
            else
            {
                q.push({y, x});
            }
        }
    }

    int sectionCnt = 0;
    int securityLevel = -1;
    while (checked != emptyCnt)
    {
        ++securityLevel;
        sectionCnt = bfs(q, wall);

        for (const t_pos &pos : wall)
        {
            q.push(pos);
        }
        wall.clear();
    }

    std::cout << securityLevel << ' ';
    std::cout << sectionCnt << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        int emptyCnt = 0;

        std::cin >> ySize >> xSize;
        for (int y = 0; y < ySize; ++y)
        {
            for (int x = 0; x < xSize; ++x)
            {
                std::cin >> map[y][x];
                emptyCnt += (map[y][x] == EMPTY);
            }
        }

        findSecurityLevel(emptyCnt);
    }
    return (0);
}
