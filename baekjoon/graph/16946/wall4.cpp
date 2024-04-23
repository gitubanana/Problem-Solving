#include <iostream>
#include <queue>
#include <vector>
#include <set>

enum e_space
{
    EMPTY = '0',
    WALL
};

struct t_pos
{
    int y;
    int x;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }

    inline bool operator<(const t_pos &other) const
    {
        if (this->y == other.y)
            return (this->x < other.x);
        return (this->y < other.y);
    }
};

const int MAX = 1000;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
bool visited[MAX][MAX];
char map[MAX][MAX + 1];
int ans[MAX][MAX];

void    bfs(const t_pos &start)
{
    int emptyCnt = 1;
    std::queue<t_pos> q;
    std::set<t_pos> wallPos;

    visited[start.y][start.x] = true;
    q.push(start);
    while (!q.empty())
    {
        const t_pos &cur = q.front();

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {cur.y + dy[dir], cur.x + dx[dir]};

            if (!(0 <= next.y && next.y < ySize)
                || !(0 <= next.x && next.x < xSize)
                || visited[next.y][next.x])
                continue ;

            if (map[next.y][next.x] == EMPTY)
            {
                visited[next.y][next.x] = true;
                q.push(next);
                ++emptyCnt;
            }
            else
            {
                wallPos.insert(next);
            }
        }
        q.pop();
    }

    for (const t_pos &wall : wallPos)
    {
        ans[wall.y][wall.x] += emptyCnt;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    char ch;

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
            ans[y][x] = map[y][x] - '0';
        }
    }

    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            if (map[y][x] == EMPTY && !visited[y][x])
                bfs({y, x});
        }
    }

    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cout << ans[y][x] % 10;
        }
        std::cout << '\n';
    }
    return (0);
}
