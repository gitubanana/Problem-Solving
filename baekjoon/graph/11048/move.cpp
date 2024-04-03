#include <iostream>
#include <queue>

struct t_pos
{
    int y, x;
};

const int MAX = 1000;

int ySize, xSize;
int dp[MAX][MAX];
int map[MAX][MAX];
int dy[] = {1, 0};
int dx[] = {0, 1};
int dirSize = sizeof(dy) / sizeof(dy[0]);

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    std::queue<t_pos> q;

    dp[0][0] = map[0][0];
    q.push({0, 0});
    while (!q.empty())
    {
        const t_pos &cur = q.front();
        const int &curCandy = dp[cur.y][cur.x];

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {cur.y + dy[dir], cur.x + dx[dir]};

            if (!(0 <= next.y && next.y < ySize)
                || !(0 <= next.x && next.x < xSize))
                continue ;

            int &nextCandy = dp[next.y][next.x];
            int cmpCandy = curCandy + map[next.y][next.x];
            if (nextCandy < cmpCandy)
            {
                nextCandy = cmpCandy;
                q.push(next);
            }
        }
        q.pop();
    }

    std::cout << (dp[ySize - 1][xSize - 1] == 0 ? map[ySize - 1][xSize - 1] : dp[ySize - 1][xSize - 1]) << '\n';
    return (0);
}
