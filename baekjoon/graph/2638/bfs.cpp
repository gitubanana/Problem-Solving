#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

enum e_space
{
    OUTSIDE_AIR = -1,
    EMPTY = 0,
    CHEESE,
    TIME_TO_GO = 3
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 100;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
std::queue<t_pos> q;
int map[MAX_SIZE][MAX_SIZE];

void    bfs(void)
{
    std::vector<t_pos> meltedCheese;

    while (!q.empty())
    {
        const t_pos &cur = q.front();

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {cur.y + dy[dir], cur.x + dx[dir]};

            if (!(0 <= next.y && next.y < ySize)
                || !(0 <= next.x && next.x < xSize))
                continue ;

            int &nextSpace = map[next.y][next.x];

            if (nextSpace == EMPTY)
            {
                nextSpace = OUTSIDE_AIR;
                q.push(next);
            }
            else if (nextSpace >= CHEESE)
            {
                ++nextSpace;
                if (nextSpace == TIME_TO_GO)
                {
                    nextSpace = OUTSIDE_AIR;
                    meltedCheese.push_back(next);
                }
            }
        }
        q.pop();
    }

    for (const t_pos &pos : meltedCheese)
    {
        q.push(pos);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            int &curSpace = map[y][x];

            std::cin >> curSpace;
        }
    }

    int ans = -1;

    q.push({0, 0});
    map[0][0] = OUTSIDE_AIR;
    while (!q.empty())
    {
        bfs();
        ++ans;
    }

    std::cout << ans << '\n';
    return (0);
}
