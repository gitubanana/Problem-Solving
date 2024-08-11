#include <iostream>
#include <cstring>

struct t_pos
{
    int y, x;
};

const int MAX_Y = 10;
const int MAX_X = 25;
const int dy[] = {1, 0, 1};
const int dx[] = {0, 1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int max;
int ySize, xSize;
bool isWall[MAX_Y][MAX_X];
int dp[1 << (MAX_Y + 1)][MAX_X];

inline bool canPut(int y, int x)
{
    if (y + 1 >= ySize || x + 1 >= xSize)
        return (false);

    return (!isWall[y][x] && !isWall[y + 1][x]
            && !isWall[y][x + 1] && !isWall[y + 1][x + 1]);
}

void   backTracking(int y=0, int x=0, int cnt=0)
{
    if (y >= ySize)
    {
        y = 0;
        ++x;

        if (x == xSize - 1)
        {
            max = std::max(max, cnt);
            return ;
        }

        int bit = 0;
        for (int y = 0; y < ySize; ++y)
        {
            bit |= (isWall[y][x] << y);
        }

        int &curDp = dp[bit][x];
        if (curDp >= cnt)
            return ;

        curDp = cnt;
    }

    if (canPut(y, x))
    {
        isWall[y][x] = isWall[y + 1][x] = isWall[y][x + 1] = isWall[y + 1][x + 1] = true;
        backTracking(y + 2, x, cnt + 1);
        isWall[y][x] = isWall[y + 1][x] = isWall[y][x + 1] = isWall[y + 1][x + 1] = false;
    }

    backTracking(y + 1, x, cnt);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        std::cin >> ySize >> xSize;
        for (int y = 0; y < ySize; ++y)
        {
            for (int x = 0; x < xSize; ++x)
            {
                std::cin >> isWall[y][x];
            }
        }

        max = 0;
        memset(dp, -1, sizeof(dp));
        backTracking();
        std::cout << '#' << t << ' ' << max << '\n';
    }

    return (0);
}
