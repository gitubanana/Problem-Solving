#include <iostream>
#include <cstring>
#include <climits>
#include <queue>

struct t_pos
{
    int y, x;
    bool jumped;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }
};

const int MAX_SIZE = 100;
const int MAX_LEVEL = 1e9;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int level[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][2];

inline bool canGo(const t_pos &pos, int myLevel)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize)
            && !visited[pos.y][pos.x][pos.jumped]
            && level[pos.y][pos.x] <= myLevel);
}

bool    canEscape(int myLevel)
{
    static const t_pos end = {ySize - 1, xSize - 1};
    static const t_pos start = {0, 0, false};

    if (level[start.y][start.x] > myLevel)
    {
        return (false);
    }

    std::queue<t_pos> q;

    memset(visited, false, sizeof(visited));
    visited[start.y][start.x][start.jumped] = true;
    q.push(start);
    while (!q.empty())
    {
        const t_pos cur = q.front();
        q.pop();

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir],
                cur.jumped
            };

            int move = 2;
            do
            {
                if (canGo(next, myLevel))
                {
                    if (next == end)
                        return (true);

                    visited[next.y][next.x][next.jumped] = true;
                    q.push(next);
                }

                if (next.jumped)
                    break ;

                next.y += dy[dir];
                next.x += dx[dir];
                next.jumped = true;
            } while (--move);
        }
    }

    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> level[y][x];
        }
    }

    if (ySize == 1 && xSize == 1)
    {
        std::cout << level[0][0] << '\n';
        return (0);
    }

    int ans = INT_MAX;
    int left = 0;
    int right = MAX_LEVEL;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (canEscape(mid))
        {
            ans = std::min(ans, mid);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    std::cout << ans << '\n';
    return (0);
}
