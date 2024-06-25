#include <iostream>
#include <cstring>
#include <vector>

enum e_space
{
    EMPTY = '.'
};

struct t_pos
{
    int y, x;
};

const int Y_SIZE = 12;
const int X_SIZE = 6;
const int EXPLODE_CNT = 4;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

bool visited[Y_SIZE][X_SIZE];
char map[Y_SIZE][X_SIZE + 1];

void    dfs(int y, int x, std::vector<t_pos> &puyos)
{
    visited[y][x] = true;
    puyos.push_back({y, x});

    const int &curPuyo = map[y][x];
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < Y_SIZE)
            || !(0 <= nextX && nextX < X_SIZE)
            || curPuyo != map[nextY][nextX]
            || visited[nextY][nextX])
            continue ;

        dfs(nextY, nextX, puyos);
    }
}

bool explodePuyo(void)
{
    bool exploded = false;

    memset(visited, false, sizeof(visited));
    for (int y = 0; y < Y_SIZE; ++y)
    {
        for (int x = 0; x < X_SIZE; ++x)
        {
            if (map[y][x] == EMPTY || visited[y][x])
                continue ;

            std::vector<t_pos> puyos;

            dfs(y, x, puyos);
            if (puyos.size() < EXPLODE_CNT)
                continue ;

            exploded = true;
            for (const t_pos &pos : puyos)
            {
                map[pos.y][pos.x] = EMPTY;
            }
        }
    }
    return (exploded);
}

void    dropPuyo(void)
{
    for (int x = 0; x < X_SIZE; ++x)
    {
        int downY = Y_SIZE - 1;

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

    for (int y = 0; y < Y_SIZE; ++y)
    {
        std::cin >> map[y];
    }

    int chainCnt = 0;
    while (true)
    {
        if (!explodePuyo())
            break ;

        dropPuyo();
        ++chainCnt;
    }

    std::cout << chainCnt << '\n';
    return (0);
}
