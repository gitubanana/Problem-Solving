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
const int X_SIZE = 10;
const int REMOVE_NUM = 3;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int circleCnt;
char map[Y_SIZE][X_SIZE + 1];
bool visited[Y_SIZE][X_SIZE];
std::vector<t_pos> toRemove;

inline bool inRange(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < Y_SIZE)
            && (0 <= pos.x && pos.x < X_SIZE));
}

void    dfs(const t_pos &cur)
{
    char &curSpace = map[cur.y][cur.x];

    ++circleCnt;
    visited[cur.y][cur.x] = true;

    for (int dir = 0; dir < dirSize; ++dir)
    {
        t_pos next = {
            cur.y + dy[dir],
            cur.x + dx[dir]
        };

        if (!inRange(next)
            || visited[next.y][next.x]
            || map[next.y][next.x] != curSpace)
            continue ;

        dfs(next);
    }

    if (circleCnt >= REMOVE_NUM)
    {
        curSpace = EMPTY;
    }
    else
    {
        toRemove.push_back(cur);
    }
}

bool removeCircle(int y, int x)
{
    if (map[y][x] == EMPTY)
        return (false);

    circleCnt = 0;
    toRemove.clear();
    memset(visited, false, sizeof(visited));

    dfs({y, x});
    if (circleCnt >= REMOVE_NUM)
    {
        for (const t_pos &pos : toRemove)
        {
            map[pos.y][pos.x] = EMPTY;
        }

        return (true);
    }

    return (false);
}

void    dropCircle(void)
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

void    pullLeft(void)
{
    int emptyX = -1;

    for (int x = 0; x < X_SIZE; ++x)
    {
        bool isEmpty = (map[Y_SIZE - 1][x] == EMPTY);

        if (isEmpty)
        {
            if (emptyX == -1)
            {
                emptyX = x;
            }
        }
        else if (emptyX != -1)
        {
            for (int y = 0; y < Y_SIZE; ++y)
            {
                map[y][emptyX] = map[y][x];
                map[y][x] = EMPTY;
            }
            ++emptyX;
        }
    }
}

int countNotEmpty(void)
{
    int cnt = 0;

    for (int y = 0; y < Y_SIZE; ++y)
    {
        for (int x = 0; x < X_SIZE; ++x)
        {
            cnt += (map[y][x] != EMPTY);
        }
    }
    return (cnt);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    while (true)
    {
        int clickCnt;

        std::cin >> clickCnt;
        if (clickCnt == 0)
            break ;

        for (int y = 0; y < Y_SIZE; ++y)
        {
            std::cin >> map[y];
        }

        while (clickCnt--)
        {
            char x;
            int y;

            std::cin >> x >> y;
            if (removeCircle(Y_SIZE - y, x - 'a'))
            {
                dropCircle();
                pullLeft();
            }
        }

        std::cout << countNotEmpty() << '\n';
    }
    return (0);
}
