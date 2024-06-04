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
    int dir;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y
                && this->x == other.x
                && this->dir == other.dir);
    }
};

const int MAX_SIZE = 100;
// 동, 북, 서, 남
const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
const char *msg = "ENWS";
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

inline std::istream &operator>>(std::istream &in, t_pos &input)
{
    static const int changeDir[] = {-1, 0, 2, 3, 1};

    in >> input.y >> input.x >> input.dir;
    --input.y, --input.x;
    input.dir = changeDir[input.dir];
    return (in);
}

inline bool isBound(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize));
}

int bfs(const t_pos &start, const t_pos &end)
{
    if (start == end)
        return (0);

    int curTime = 1;
    std::queue<t_pos> q;

    visited[start.y][start.x] |= (1 << start.dir);
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            t_pos cur = q.front();
            q.pop();

            int moveCnt = 3;
            t_pos next = cur;
            while (moveCnt--)
            {
                next.y += dy[next.dir];
                next.x += dx[next.dir];
                if (!isBound(next)
                    || map[next.y][next.x] == WALL)
                    break ;

                if (visited[next.y][next.x] & (1 << next.dir))
                    continue ;

                if (next == end)
                    return (curTime);

                visited[next.y][next.x] |= (1 << next.dir);
                q.push(next);
            }

            for (int dd = -1; dd <= 2; dd += 3)
            {
                cur.dir = (cur.dir + dd) % dirSize;
                if (cur.dir == -1)
                    cur.dir = dirSize - 1;

                if (visited[cur.y][cur.x] & (1 << cur.dir))
                    continue ;

                if (cur == end)
                    return (curTime);

                visited[cur.y][cur.x] |= (1 << cur.dir);
                q.push(cur);
            }
        }
        ++curTime;
    }
    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos start, end;

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
        }
    }
    std::cin >> start >> end;

    std::cout << bfs(start, end) << '\n';    
    return (0);
}
