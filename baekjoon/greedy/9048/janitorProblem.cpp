#include <iostream>
#include <cstring>
#include <climits>

const int MAX_SIZE = 30;

int ySize, xSize;
bool isLight[MAX_SIZE + 1][MAX_SIZE + 1];

void    solve(void)
{
    int lightCnt;

    std::cin >> ySize >> xSize >> lightCnt;
    while (lightCnt--)
    {
        int y, x;

        std::cin >> y >> x;
        isLight[y][x] = true;
    }

    int moveCnt = ySize * 2 + xSize + 1;
    for (int y = 1; y <= ySize; ++y)
    {
        int addMove = INT_MAX;

        for (int limit = 1; limit <= xSize + 1; ++limit)
        {
            int left = 0;
            for (int x = 1; x < limit; ++x)
            {
                if (!isLight[y][x])
                    continue ;

                left = x;
            }

            int right = xSize + 1;
            for (int x = xSize; x >= limit; --x)
            {
                if (!isLight[y][x])
                    continue ;

                right = x;
            }

            addMove = std::min(addMove, left + (xSize - right + 1));
        }

        moveCnt += addMove * 2;
    }

    std::cout << moveCnt << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        solve();
        memset(isLight, false, sizeof(isLight));
    }
    return (0);
}
