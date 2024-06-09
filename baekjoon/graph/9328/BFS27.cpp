#include <iostream>
#include <unordered_set>
#include <cstring>
#include <queue>

enum e_space
{
        EMPTY = '.',
        WALL = '*',
        MONEY = '$'
};

struct t_pos
{
        int y, x;
};

using t_uset = std::unordered_set<int>;

const int MAX_SIZE = 100;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int key, getMoney;
int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];
bool visited[MAX_SIZE][MAX_SIZE];
std::string strKey;
std::queue<t_pos> q;

inline bool isDoor(const char &space)
{
        return ('A' <= space && space <= 'Z');
}

inline bool isKey(const char &space)
{
        return ('a' <= space && space <= 'z');
}

inline bool canGo(const t_pos &pos)
{
        return ((0 <= pos.y && pos.y < ySize)
                        && (0 <= pos.x && pos.x < xSize)
                        && map[pos.y][pos.x] != WALL
                        && !visited[pos.y][pos.x]);
}

void    enterBuilding()
{
        for (int y = 0; y < ySize; ++y)
        {
                int step = (y == 0 || y == ySize - 1) ? 1 : xSize - 1;

                for (int x = 0; x < xSize; x += step)
                {
                        char &curSpace = map[y][x];

                        if (curSpace == WALL)
                        {
                                continue ;
                        }
                        else if (curSpace == MONEY)
                        {
                                ++getMoney;
                                curSpace = EMPTY;
                        }
                        else if (isDoor(curSpace))
                        {
                                if (!(key & (1 << (curSpace - 'A'))))
                                        continue ;
                        }

                        visited[y][x] = true;
                        q.push({y, x});
                }
        }
}

void    initSimulation(void)
{
        key = 0;
        getMoney = 0;

        if (strKey != "0")
        {
                for (const char &ch : strKey)
                {
                        key |= (1 << (ch - 'a'));
                }
        }

        for (int y = 0; y < ySize; ++y)
        {
                int step = (y == 0 || y == ySize - 1) ? 1 : xSize - 1;

                for (int x = 0; x < xSize; x += step)
                {
                        char &curSpace = map[y][x];

                        if (isKey(curSpace))
                                key |= (1 << (curSpace - 'a'));
                }
        }
}

void bfs(void)
{
        memset(visited, false, sizeof(visited));
        enterBuilding();
    while (!q.empty())
    {
            const t_pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                    t_pos next = {
                            cur.y + dy[dir],
                            cur.x + dx[dir],
                    };

                    if (!canGo(next))
                            continue ;

                    char &nextSpace = map[next.y][next.x];

                    visited[next.y][next.x] = true;
                    if (nextSpace == MONEY)
                    {
                            ++getMoney;
                            nextSpace = EMPTY;
                    }
                    else if (isDoor(nextSpace))
                    {
                            if (!(key & (1 << (nextSpace - 'A'))))
                                    continue ;
                    }
                    else if (isKey(nextSpace))
                    {
                            key |= (1 << (nextSpace - 'a'));
                    }

                    q.push(next);
            }
    }
}

int     main(void)
{
        std::cin.tie(0)->sync_with_stdio(0);

        int testCnt;

        std::cin >> testCnt;
        while (testCnt--)
        {
                std::cin >> ySize >> xSize;
                for (int y = 0; y < ySize; ++y)
                {
                        std::cin >> map[y];
                }
                std::cin >> strKey;

                                int bfsCnt = 27;

                                initSimulation();
                                while (bfsCnt--)
                                {
                                        bfs();
                                }

                std::cout << getMoney << '\n';
        }
        return (0);
}
