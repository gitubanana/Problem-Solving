#include <iostream>
#include <climits>
#include <cstring>
#include <queue>

enum e_space
{
    WALL = 'T',
    EMPTY = 'G',
    START = 'M',
    END = 'D',
    BEE = 'H'
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 800;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size;
int movePerMin;
int beeTime[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];
std::queue<t_pos> beeQ;

inline bool inRange(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < size)
            && (0 <= pos.x && pos.x < size));
}

void    moveBees(void)
{
    while (!beeQ.empty())
    {
        const t_pos cur = beeQ.front();
        const int &curTime = beeTime[cur.y][cur.x];
        beeQ.pop();

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir]
            };

            if (!inRange(next)
                || map[next.y][next.x] != EMPTY
                || beeTime[next.y][next.x] != INT_MAX)
                continue ;

            beeTime[next.y][next.x] = curTime + 1;
            beeQ.push(next);
        }
    }
}

bool canGoHome(const t_pos &start, int curTime)
{
    std::queue<t_pos> q;

    memset(visited, false, sizeof(visited));
    visited[start.y][start.x] = true;
    q.push(start);
    while (!q.empty())
    {
        int move = movePerMin;

        while (!q.empty() && move--)
        {
            int qSize = q.size();

            while (qSize--)
            {
                const t_pos cur = q.front();
                q.pop();

                if (beeTime[cur.y][cur.x] <= curTime)
                    continue ;

                for (int dir = 0; dir < dirSize; ++dir)
                {
                    t_pos next = {
                        cur.y + dy[dir],
                        cur.x + dx[dir]
                    };

                    if (!inRange(next)
                        || map[next.y][next.x] == WALL
                        || visited[next.y][next.x])
                        continue ;

                    if (map[next.y][next.x] == END)
                        return (true);

                    visited[next.y][next.x] = true;
                    q.push(next);
                }
            }
        }

        ++curTime;
    }

    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos start = {-1, -1};

    std::cin >> size >> movePerMin;
    for (int y = 0; y < size; ++y)
    {
        std::cin >> map[y];

        for (int x = 0; x < size; ++x)
        {
            switch (map[y][x])
            {
            case BEE:
                beeTime[y][x] = 0;
                beeQ.push({y, x});
                break;
            case START:
                map[y][x] = EMPTY;
                start.y = y, start.x = x;
            default:
                beeTime[y][x] = INT_MAX;
                break ;
            }
        }
    }

    moveBees();

    int ans = -1;
    int left = 0;
    int right = MAX_SIZE * MAX_SIZE;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (canGoHome(start, mid))
        {
            ans = std::max(ans, mid);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    std::cout << ans << '\n';
    return (0);
}
