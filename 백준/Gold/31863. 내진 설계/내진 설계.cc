#include <iostream>
#include <queue>

enum e_space
{
    EPICENTER = '@',
    EMPTY = '.',
    WEAK = '*',
    STRONG = '#',
    WALL = '|'
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 1000;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int collapsed;
int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];

inline bool inRange(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize));
}

inline void attackBuilding(const t_pos &pos, std::queue<t_pos> &q)
{
    char &space = map[pos.y][pos.x];

    switch (space)
    {
    case WEAK:
        ++collapsed;
        space = EMPTY;
        q.push(pos);
        break;
    case STRONG:
        space = WEAK;
        break;
    }
}

void bfs(const t_pos &start)
{
    std::queue<t_pos> q;

    for (int dir = 0; dir < dirSize; ++dir)
    {
        int moveCnt = 2;
        t_pos next = {
            start.y + dy[dir],
            start.x + dx[dir]
        };

        while (moveCnt-- && inRange(next))
        {
            if (map[next.y][next.x] == WALL)
                break ;

            attackBuilding(next, q);
            next.y += dy[dir];
            next.x += dx[dir];
        }
    }

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

            if (!inRange(next))
                continue ;

            attackBuilding(next, q);
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int buildingCnt = 0;
    t_pos start = {-1, -1};

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
        for (int x = 0; x < xSize; ++x)
        {
            switch (map[y][x])
            {
            case EPICENTER:
                start.y = y, start.x = x;
                break;
            case WEAK: case STRONG:
                ++buildingCnt;
                break;
            }
        }
    }

    bfs(start);
    std::cout << collapsed << ' ' << buildingCnt - collapsed << '\n';
    return (0);
}
