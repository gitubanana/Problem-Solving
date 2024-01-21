#include <iostream>

enum e_space
{
    EMPTY = '.',
    WALL = 'T'
};

const int MAX = 5;
char map[MAX][MAX + 1];
bool visited[MAX][MAX];
int ySize, xSize;
int goalDist, ans;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void back_tracking(int curY, int curX, int depth)
{
    if (depth == goalDist)
    {
        ans += (curY == 0 && curX == xSize - 1);
        return ;
    }

    visited[curY][curX] = true;
    for (int i = 0; i < 4; ++i)
    {
        int nextY = curY + dy[i];
        int nextX = curX + dx[i];

        if (!(0 <= nextY && nextY < ySize)
            || !(0 <= nextX && nextX < xSize)
            || map[nextY][nextX] == WALL
            || visited[nextY][nextX])
            continue ;
        back_tracking(nextY, nextX, depth + 1);
    }
    visited[curY][curX] = false;
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize >> goalDist;
    for (int y = 0; y < ySize; ++y)
        std::cin >> map[y];

    back_tracking(ySize - 1, 0, 1);

    std::cout << ans << '\n';
    return 0;
}
