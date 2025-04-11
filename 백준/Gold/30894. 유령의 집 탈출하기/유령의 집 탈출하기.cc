#include <iostream>
#include <vector>
#include <queue>

enum e_space
{
    EMPTY = '.',
    WALL = '#'
};

struct t_pos
{
    int y, x;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }
};

const int MAX_SIZE = 200;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];
char gatcha[MAX_SIZE][MAX_SIZE];
char visited[MAX_SIZE][MAX_SIZE];
std::vector<t_pos> ghosts;

inline bool isBound(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize));
}

inline std::istream &operator>>(std::istream &in, t_pos &pos)
{
    in >> pos.y >> pos.x;
    --pos.y, --pos.x;
    return (in);
}

void    saveGatcha(void)
{
    for (int i = 0; i < dirSize; ++i)
    {
        for (const t_pos &ghost : ghosts)
        {
            char &dir = map[ghost.y][ghost.x];
            t_pos cur = {
                ghost.y + dy[dir],
                ghost.x + dx[dir]
            };

            while (isBound(cur))
            {
                if (map[cur.y][cur.x] != EMPTY)
                    break ;

                gatcha[cur.y][cur.x] |= (1 << i);
                cur.y += dy[dir];
                cur.x += dx[dir];
            }

            dir = (dir + 1) % dirSize;
        }
    }
}

void    bfs(const t_pos &start, const t_pos &end)
{
    int gIdx = 1;
    int move = 1;
    std::queue<t_pos> q;

    visited[start.y][start.x] |= (1 << 0);
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();
        int bit = (1 << gIdx);

        while (qSize--)
        {
            const t_pos cur = q.front();
            q.pop();

            if (!(visited[cur.y][cur.x] & bit)
                && !(gatcha[cur.y][cur.x] & bit))
            {
                visited[cur.y][cur.x] |= bit;
                q.push(cur);
            }

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {
                    cur.y + dy[dir],
                    cur.x + dx[dir]
                };

                if (!isBound(next)
                    || map[next.y][next.x] != EMPTY
                    || visited[next.y][next.x] & bit
                    || gatcha[next.y][next.x] & bit)
                    continue ;

                if (next == end)
                {
                    std::cout << move << '\n';
                    return ;
                }

                visited[next.y][next.x] |= bit;
                q.push(next);
            }
        }

        gIdx = (gIdx + 1) % dirSize;
        ++move;
    }

    std::cout << "GG" << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos start, end;

    std::cin >> ySize >> xSize;
    std::cin >> start >> end;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];

        for (int x = 0; x < xSize; ++x)
        {
            char &space = map[y][x];

            if (std::isdigit(space))
            {
                space -= '0';
                ghosts.push_back({y, x});
            }
        }
    }

    saveGatcha();
    bfs(start, end);
    return (0);
}
