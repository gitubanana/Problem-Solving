#include <iostream>
#include <climits>
#include <cstring>
#include <queue>

enum e_space
{
    OCEAN = 0,
    LAND
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 100;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int id = 2, size;
int map[MAX_SIZE][MAX_SIZE];
std::queue<t_pos> q;

void    dfs(int y, int x)
{
    q.push({y, x});
    map[y][x] = id;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < size)
            || !(0 <= nextX && nextX < size)
            || map[nextY][nextX] != LAND)
            continue ;

        dfs(nextY, nextX);
    }
}

int bfs(void)
{
    int ans = INT_MAX;
    int curTime = 0;

    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            const t_pos cur = q.front();
            const int &curId = map[cur.y][cur.x];
            q.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {
                    cur.y + dy[dir],
                    cur.x + dx[dir]
                };

                if (!(0 <= next.y && next.y < size)
                    || !(0 <= next.x && next.x < size)
                    || map[next.y][next.x] == curId)
                    continue ;

                int &nextId = map[next.y][next.x];
                if (nextId != OCEAN)
                {
                    ans =  std::min(ans, curTime * 2 + (curId > nextId));
                    continue ;
                }

                nextId = curId;
                q.push(next);
            }
        }
        if (ans != INT_MAX)
            return (ans);

        ++curTime;
    }
    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            if (map[y][x] != LAND)
                continue ;

            dfs(y, x);
            ++id;
        }
    }

    std::cout << bfs() << '\n';
    return (0);
}
