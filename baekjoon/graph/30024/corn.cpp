#include <iostream>
#include <queue>

const int MAX_SIZE = 1000;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

struct t_pos
{
    int y, x;

    inline bool operator<(const t_pos &other) const
    {
        return (map[y][x] < map[other.y][other.x]);
    }
};

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    int getCnt;
    std::priority_queue<t_pos> pq;

    std::cin >> getCnt;
    for (int y = 0; y < ySize; ++y)
    {
        int step = (y == 0 || y == ySize - 1 ? 1 : xSize - 1);
        for (int x = 0; x < xSize; x += step)
        {
            if (visited[y][x])
                break ;

            visited[y][x] = true;
            pq.push({y, x});
        }
    }

    while (getCnt--)
    {
        t_pos cur = pq.top();
        pq.pop();

        std::cout << cur.y + 1 << ' ' << cur.x + 1 << '\n';
        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir]
            };

            if (!(0 <= next.y && next.y < ySize)
                || !(0 <= next.x && next.x < xSize)
                || visited[next.y][next.x])
                continue ;

            visited[next.y][next.x] = true;
            pq.push(next);
        }
    }

    return (0);
}
