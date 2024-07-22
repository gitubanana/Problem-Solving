#include <iostream>
#include <queue>

struct t_pos
{
    int y, x;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }
};

const int MAX_MOVE = 10;
const int MAX_SIZE = 500;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size, halfDayMove;
bool isWall[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][MAX_MOVE * 2 + 1];
const char *msg[] = {"moon", "sun"};

inline bool isBound(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < size)
            && (0 <= pos.x && pos.x < size));
}

void    bfs(void)
{
    static const t_pos end = {size - 1, size - 1};

    int day = 1;
    int move = 0;
    bool isDay = true;
    std::queue<t_pos> q;

    visited[0][0][0] = true;
    q.push({0, 0});
    while (!q.empty())
    {
        int qSize = q.size();
        bool nowIsDay = isDay;

        if (++move % halfDayMove == 0)
        {
            isDay ^= true;
            if (isDay)
            {
                ++day;
                move = 0;
            }
        }

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

                if (!isBound(next) || visited[next.y][next.x][move])
                    continue ;

                if (nowIsDay)
                {
                    if (isWall[next.y][next.x])
                        continue ;
                }
                else
                {
                    bool outOfBound = false;

                    while (isWall[next.y][next.x])
                    {
                        next.y += dy[dir];
                        next.x += dx[dir];

                        if (!isBound(next))
                        {
                            outOfBound = true;
                            break ;
                        }
                    }

                    if (outOfBound)
                        continue ;
                }

                if (next == end)
                {
                    std::cout << day << ' ' << msg[isDay] << '\n';
                    return ;
                }

                if (visited[next.y][next.x][move])
                    continue ;

                visited[next.y][next.x][move] = true;
                q.push(next);
            }
        }
    }

    std::cout << "-1" << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size >> halfDayMove;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> isWall[y][x];
        }
    }

    if (size == 1)
    {
        std::cout << "1 sun" << '\n';
    }
    else
    {
        bfs();
    }
    return (0);
}
