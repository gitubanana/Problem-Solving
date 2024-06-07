#include <iostream>
#include <deque>

enum e_space
{
    HAY = '#',
    WALL = '!'
};

struct t_pos
{
    int y, x;
    int breakCnt;
};

const int MAX_SIZE = 1002;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

t_pos start;
char map[MAX_SIZE][MAX_SIZE];

int bfs()
{
    std::deque<t_pos> q;

    map[start.y][start.x] = WALL;
    q.push_front(start);
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

            if (!(0 <= next.y && next.y < MAX_SIZE)
                || !(0 <= next.x && next.x < MAX_SIZE)
                || map[next.y][next.x] == WALL)
                continue;

            if (next.y == 0 && next.x == 0)
                return next.breakCnt;

            if (map[next.y][next.x] == HAY)
            {
                ++next.breakCnt;
                q.push_back(next);
            }
            else
            {
                q.push_front(next);
            }
            map[next.y][next.x] = WALL;
        }
    }

    return -1;
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int hayCnt;
    t_pos hay;

    std::cin >> hayCnt >> start.y >> start.x;
    while (hayCnt--)
    {
        std::cin >> hay.y >> hay.x;
        map[hay.y][hay.x] = HAY;
    }

    std::cout << bfs() << '\n';
    return 0;
}