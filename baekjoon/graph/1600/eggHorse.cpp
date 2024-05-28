#include <iostream>
#include <queue>

enum e_space
{
    EMPTY = 0,
    WALL
};

struct t_pos
{
    int y, x;
    int remainHorse;
};

const int MAX_SIZE = 200;
const int hDy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int hDx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int hDirSize = sizeof(hDy) / sizeof(hDy[0]);
const int mDy[] = {-1, 1, 0, 0};
const int mDx[] = {0, 0, -1, 1};
const int mDirSize = sizeof(mDy) / sizeof(mDy[0]);

int ySize, xSize;
int visited[MAX_SIZE][MAX_SIZE];
int map[MAX_SIZE][MAX_SIZE];

inline bool canGo(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize)
            && map[pos.y][pos.x] == EMPTY
            && !(visited[pos.y][pos.x] & (1 << pos.remainHorse)));
}

inline bool isEnd(const t_pos &pos)
{
    return (pos.y == ySize - 1
            && pos.x == xSize - 1);
}

int bfs(const t_pos &start)
{
    if (isEnd(start))
        return (0);

    int totalMoveCnt = 1;
    std::queue<t_pos> q;

    visited[start.y][start.x] |= (1 << start.remainHorse);
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            const t_pos cur = q.front();
            q.pop();

            if (cur.remainHorse)
            {
                for (int dir = 0; dir < hDirSize; ++dir)
                {
                    t_pos next = {cur.y + hDy[dir], cur.x + hDx[dir], cur.remainHorse - 1};

                    if (!canGo(next))
                        continue ;

                    if (isEnd(next))
                        return (totalMoveCnt);

                    visited[next.y][next.x] |= (1 << next.remainHorse);
                    q.push(next);
                }
            }

            for (int dir = 0; dir < mDirSize; ++dir)
            {
                t_pos next = {cur.y + mDy[dir], cur.x + mDx[dir], cur.remainHorse};

                if (!canGo(next))
                    continue ;

                if (isEnd(next))
                    return (totalMoveCnt);

                visited[next.y][next.x] |= (1 << next.remainHorse);
                q.push(next);
            }
        }
        ++totalMoveCnt;
    }
    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int horseMoveCnt;

    std::cin >> horseMoveCnt >> xSize >> ySize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    std::cout << bfs({0, 0, horseMoveCnt}) << '\n';
    return (0);
}
