#include <iostream>

enum e_space
{
        HOLE = 'H'
};

const int MAX_SIZE = 50;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ans;
int ySize, xSize;
int dp[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];

int     dfs(int y=0, int x=0)
{
        bool &curVisited = visited[y][x];
        if (curVisited)
        {
                std::cout << "-1" << '\n';
                exit(0);
        }

        int &curDp = dp[y][x];
        if (curDp != 0)
                return (curDp);

        curVisited = true;

        int step = map[y][x] - '0';
        for (int dir = 0; dir < dirSize; ++dir)
        {
                int nextY = y + dy[dir] * step;
                int nextX = x + dx[dir] * step;

                if (!(0 <= nextY && nextY < ySize)
                        || !(0 <= nextX && nextX < xSize)
                        || map[nextY][nextX] == HOLE)
                        continue ;

                curDp = std::max(
                                curDp,
                                1 + dfs(nextY, nextX)
                );
        }

        if (curDp == 0)
                curDp = 1;

        curVisited = false;
        return (curDp);
}

int     main(void)
{
        std::cin.tie(0)->sync_with_stdio(0);

        std::cin >> ySize >> xSize;
        for (int y = 0; y < ySize; ++y)
        {
                std::cin >> map[y];
        }

        std::cout << dfs() << '\n';
        return (0);
}
