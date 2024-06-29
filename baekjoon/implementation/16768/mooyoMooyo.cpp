#include <iostream>
#include <cstring>
#include <vector>

enum e_space
{
    EMPTY = '0'
};

struct t_pos
{
    int y, x;
};

const int MAX_Y_SIZE = 100;
const int X_SIZE = 10;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, explodeCnt;
char map[MAX_Y_SIZE][X_SIZE + 1];
bool visited[MAX_Y_SIZE][X_SIZE];

void    dfs(const t_pos &cur, std::vector<t_pos> &explodePos)
{
    explodePos.push_back(cur);
    visited[cur.y][cur.x] = true;

    const char &curSpace = map[cur.y][cur.x];
    for (int dir = 0; dir < dirSize; ++dir)
    {
        t_pos next = {
            cur.y + dy[dir],
            cur.x + dx[dir],
        };

        if (!(0 <= next.y && next.y < ySize)
            || !(0 <= next.x && next.x < X_SIZE)
            || map[next.y][next.x] != curSpace
            || visited[next.y][next.x])
            continue ;

        dfs(next, explodePos);
    }
}

bool explode(void)
{
    t_pos pos = {0, 0};
    bool exploded = false;

    for (; pos.y < ySize; ++pos.y)
    {
        for (pos.x = 0; pos.x < X_SIZE; ++pos.x)
        {
            if (map[pos.y][pos.x] == EMPTY
                || visited[pos.y][pos.x])
                continue ;

            std::vector<t_pos> explodePos;

            dfs(pos, explodePos);
            if (explodePos.size() < explodeCnt)
                continue ;

            exploded = true;
            for (const t_pos &pos : explodePos)
            {
                map[pos.y][pos.x] = EMPTY;
            }
        }
    }
    return (exploded);
}

void    workGravity(void)
{
    for (int x = 0; x < X_SIZE; ++x)
    {
        int downY = ySize - 1;

        while (downY >= 0 && map[downY][x] != EMPTY)
        {
            --downY;
        }

        for (int y = downY - 1; y >= 0; --y)
        {
            if (map[y][x] == EMPTY)
                continue ;

            map[downY--][x] = map[y][x];
            map[y][x] = EMPTY;
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> explodeCnt;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
    }

    while (explode())
    {
        workGravity();
        memset(visited, false, sizeof(visited));
    }

    for (int y = 0; y < ySize; ++y)
    {
        std::cout << map[y] << '\n';
    }
    return (0);
}
