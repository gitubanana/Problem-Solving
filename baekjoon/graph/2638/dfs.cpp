#include <iostream>
#include <cstring>

enum e_space
{
    EMPTY = 0,
    CHEESE
};

const int MAX_SIZE = 100;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int cheeseCnt;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

void    dfs(int y, int x)
{
    visited[y][x] = true;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < ySize)
            || !(0 <= nextX && nextX < xSize)
            || visited[nextY][nextX])
            continue ;

        int &nextSpace = map[nextY][nextX];

        if (nextSpace >= CHEESE)
        {
            ++nextSpace;
        }
        else
        {
            dfs(nextY, nextX);
        }
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
            cheeseCnt += (curSpace == CHEESE);
        }
    }

    int ans = 0;
    while (cheeseCnt)
    {
        dfs(0, 0);

        for (int y = 0; y < ySize; ++y)
        {
            for (int x = 0; x < xSize; ++x)
            {
                int &curSpace = map[y][x];

                if (curSpace == EMPTY)
                    continue ;

                if (curSpace < 3)
                {
                    curSpace = CHEESE;
                }
                else
                {
                    --cheeseCnt;
                    curSpace = EMPTY;
                }
            }
        }

        if (cheeseCnt)
        {
            memset(visited, 0, sizeof(visited));
        }
        ++ans;
    }

    std::cout << ans << '\n';
    return (0);
}
