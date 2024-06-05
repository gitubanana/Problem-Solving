#include <iostream>
#include <deque>

enum e_space
{
    EMPTY = '0',
    WALL
};

struct t_pos
{
    int y, x;
    int breakCnt;
};

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);
const int MAX_SIZE = 100;

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];
bool visited[MAX_SIZE][MAX_SIZE];

int bfs()
{
    if (ySize == 1 && xSize == 1)
    {
        return (0);
    }
    
    std::deque<t_pos> q;

    visited[0][0] = true;
    q.push_back({0, 0});
    while (!q.empty())
    {
        t_pos cur = q.front();
        q.pop_front();

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir],
                cur.breakCnt
            };

            if (!(0 <= next.y && next.y < ySize)
                || !(0 <= next.x && next.x < xSize)
                || visited[next.y][next.x])
                continue;

            if (next.y == ySize - 1
                && next.x == xSize - 1)
            {
                return next.breakCnt;
            }

            visited[next.y][next.x] = true;
            if (map[next.y][next.x] == WALL)
            {
                ++next.breakCnt;
                q.push_back(next);
            }
            else
            {
                q.push_front(next);
            }
        }
    }

    return -1;
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> xSize >> ySize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
    }

    std::cout << bfs() << '\n';
    return 0;
}
