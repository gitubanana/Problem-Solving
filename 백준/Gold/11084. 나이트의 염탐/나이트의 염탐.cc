#include <iostream>
#include <cstring>
#include <queue>

struct t_pos
{
    int y, x;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }
};

const int MAX_SIZE = 400;
const int DIVISOR = 1'000'000'009;
const int FAIL = -1;
const int dy[] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int64_t cnt[MAX_SIZE][MAX_SIZE];
t_pos start, end;

inline bool inRange(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize));
}

void bfs()
{
    if (start == end)
    {
        std::cout << "0 1" << '\n';
        return ;
    }

    int dist = 0;
    int64_t endCnt = 0;
    bool foundEnd = false;
    std::queue<t_pos> q;

    cnt[start.y][start.x] = 1;
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();

        ++dist;
        while (qSize--)
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

                if (cnt[next.y][next.x] == 0)
                {
                    q.push(next);
                }

                cnt[next.y][next.x] += cnt[cur.y][cur.x];
                cnt[next.y][next.x] %= DIVISOR;
                if (next == end)
                {
                    foundEnd = true;
                }
            }
        }

        if (foundEnd)
        {
            std::cout << dist << ' ' << cnt[end.y][end.x] << '\n';
            return ;
        }
    }

    std::cout << "None" << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;

    end = {ySize - 1, xSize - 1};
    bfs();
    return (0);
}
