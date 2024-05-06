#include <iostream>

const int MAX = 500;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size;
int bamboo[MAX][MAX];
int cnt[MAX][MAX];

int    dfs(int y, int x)
{
    int &curCnt = cnt[y][x];

    if (curCnt > 0)
        return curCnt;

    int plus = 0;

    curCnt = 1;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < size)
            || !(0 <= nextX && nextX < size)
            || bamboo[y][x] >= bamboo[nextY][nextX])
            continue ;

        plus = std::max(plus, dfs(nextY, nextX));
    }
    return curCnt += plus;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
            std::cin >> bamboo[y][x];
    }

    int ans = 0;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
            ans = std::max(ans, dfs(y, x));
    }

    std::cout << ans << '\n';
    return (0);
}
