#include <iostream>
#include <climits>

const int MAX_Y = 30 + 1;
const int MAX_X = 10 + 2;
const int DEPTH_LIMIT = 3;

int min = INT_MAX;
int ySize, xSize;
bool isLine[MAX_Y][MAX_X];

bool isOk(void)
{
    for (int x = 1; x <= xSize; ++x)
    {
        int curX = x;

        for (int y = 1; y <= ySize; ++y)
        {
            if (isLine[y][curX])
                ++curX;
            else if (isLine[y][curX - 1])
                --curX;
        }

        if (curX != x)
            return (false);
    }

    return (true);
}

void    backTracking(int depth=0)
{
    if (min <= depth)
    {
        return ;
    }

    if (isOk())
    {
        min = depth;
        return ;
    }

    if (depth == DEPTH_LIMIT)
    {
        return ;
    }

    for (int x = 1; x <= xSize; ++x)
    {
        for (int y = 1; y <= ySize; ++y)
        {
            if (isLine[y][x - 1] || isLine[y][x] || isLine[y][x + 1])
                continue ;

            isLine[y][x] = true;
            backTracking(depth + 1);
            isLine[y][x] = false;

            while (!isLine[y][x - 1] && !isLine[y][x + 1])
            {
                ++y;
            }
        }
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> xSize >> eCnt >> ySize;
    while (eCnt--)
    {
        int y, x;

        std::cin >> y >> x;
        isLine[y][x] = true;
    }

    backTracking();
    std::cout << (min == INT_MAX ? -1 : min) << '\n';
    return 0;
}