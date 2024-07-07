#include <iostream>
#include <cstring>
#include <climits>

const int MAX_Y_SIZE = 13;
const int MAX_X_SIZE = 20;

int minCnt;
int ySize, xSize, okSize;
bool startMap[MAX_Y_SIZE][MAX_X_SIZE];

inline bool isOk(bool map[MAX_Y_SIZE][MAX_X_SIZE])
{
    for (int x = 0; x < xSize; ++x)
    {
        bool isNotOk = true;
        for (int y = 0; y < ySize; )
        {
            int curSize = 1;
            const bool &cur = map[y][x];

            while (curSize < okSize)
            {
                if (++y >= ySize)
                    break ;

                if (cur != map[y][x])
                    break ;

                ++curSize;
            }

            if (curSize >= okSize)
            {
                isNotOk = false;
                break ;
            }
        }

        if (isNotOk)
            return (false);
    }
    return (true);
}

void    backTracking(bool cur[MAX_Y_SIZE][MAX_X_SIZE], int changeY=0, int changeCnt=0)
{
    if (changeY == ySize)
    {
        if (isOk(cur))
            minCnt = std::min(minCnt, changeCnt);

        return ;
    }
 
    backTracking(cur, changeY + 1, changeCnt);
    if (minCnt <= changeCnt + 1)
    {
        return ;
    }

    bool next[MAX_Y_SIZE][MAX_X_SIZE];

    memcpy(next, cur, sizeof(startMap));
    for (int change = false; change <= true; ++change)
    {
        for (int x = 0; x < xSize; ++x)
        {
            next[changeY][x] = change;
        }

        backTracking(next, changeY + 1, changeCnt + 1);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        std::cin >> ySize >> xSize >> okSize;
        for (int y = 0; y < ySize; ++y)
        {
            for (int x = 0; x < xSize; ++x)
            {
                std::cin >> startMap[y][x];
            }
        }

        minCnt = ySize;
        backTracking(startMap);
        std::cout << '#' << t << ' ' << minCnt << '\n';
    }

    return (0);
}
