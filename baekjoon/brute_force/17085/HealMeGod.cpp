#include <iostream>

enum e_space
{
    EMPTY = '.',
    CROSS = '#'
};

const int CROSS_CNT = 2;
const int MAX_SIZE = 15;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ans;
int ySize, xSize;
bool visited[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];

int getCrossSize(int y, int x)
{
    int ret = 100;

    for (int dir = 0; dir < dirSize; ++dir)
    {
        int cmp = 0;
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        while ((0 <= nextY && nextY < ySize)
            && (0 <= nextX && nextX < xSize)
            && map[nextY][nextX] == CROSS
            && !visited[nextY][nextX]
            && cmp < ret)
        {
            nextY += dy[dir];
            nextX += dx[dir];
            ++cmp;
        }

        ret = std::min(ret, cmp);
    }
    return ret == 100 ? 0 : ret;
}

void makeVisited(int y, int x, int crossSize, bool value)
{
    visited[y][x] = value;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int cnt = crossSize;
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        while (cnt--)
        {
            visited[nextY][nextX] = value;
            nextY += dy[dir];
            nextX += dx[dir];
        }
    }
}

void backtracking(int y=0, int x=0, int mul=1, int depth=0)
{
    if (depth == CROSS_CNT)
    {
        ans = std::max(ans, mul);
        return ;
    }

    while (true)
    {
        if (x >= xSize)
        {
            ++y;
            x = 0;
        }

        if (y >= ySize)
        {
            break ;
        }

        if (map[y][x] == CROSS
            && !visited[y][x])
        {
            int crossSize = getCrossSize(y, x);

            for (int i = 0; i <= crossSize; ++i)
            {
                makeVisited(y, x, i, true);
                backtracking(y, x + 1, mul * (i * 4 + 1), depth + 1);
                makeVisited(y, x, i, false);
            }
        }

        ++x;
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
    }

    backtracking();
    std::cout << ans << '\n';
    return 0;
}
