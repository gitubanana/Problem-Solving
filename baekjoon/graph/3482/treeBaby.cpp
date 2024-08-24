#include <iostream>
#include <cstring>

enum e_space
{
    WALL = '#',
    HOOK = '.'
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 1000;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int maxLen;
t_pos farPos;
int ySize, xSize;
bool visited[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];

inline bool inRange(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize));
}

void    dfs(const t_pos &cur, int depth=0)
{
    if (maxLen < depth)
    {
        maxLen = depth;
        farPos = cur;
    }

    visited[cur.y][cur.x] = true;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        t_pos next = {
            cur.y + dy[dir],
            cur.x + dx[dir]
        };

        if (!inRange(next)
            || visited[next.y][next.x]
            || map[next.y][next.x] != HOOK)
            continue ;

        dfs(next, depth + 1);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        t_pos start = {-1, -1};

        std::cin >> xSize >> ySize;
        for (int y = 0; y < ySize; ++y)
        {
            std::cin >> map[y];
            if (start.y != -1)
                continue ;

            for (int x = 0; x < xSize; ++x)
            {
                if (map[y][x] == HOOK)
                {
                    start.y = y, start.x = x;
                    break ;
                }
            }
        }

        maxLen = -1;
        memset(visited, false, sizeof(visited));
        dfs(start);

        maxLen = -1;
        memset(visited, false, sizeof(visited));
        dfs(farPos);

        std::cout << "Maximum rope length is " << maxLen << '.' << '\n';
    }
    return (0);
}
