#include <iostream>

const int Y_MAX = 32;
const int X_MAX = 11;

int limit;
int ySize, xSize;
bool ladder[Y_MAX][X_MAX];

inline bool checkAllGo(void)
{
    for (int x = 1; x <= xSize; ++x)
    {
        int curX = x;
        for (int y = 1; y <= ySize; ++y)
        {
            if (ladder[y][curX])
                ++curX;
            else if (ladder[y][curX - 1])
                --curX;
        }

        if (curX != x)
            return (false);
    }
    return (true);
}

bool    back_tracking(int y=1, int x=1, int depth=0)
{
    if (checkAllGo())
    {
        return (true);
    }

    if (depth == limit)
    {
        return (false);
    }

    while (true)
    {
        if (x >= xSize + 1)
        {
            ++y;
            x = 1;
        }

        if (y > ySize)
            break ;

        if (ladder[y][x])
        {
            ++x;
        }
        else
        {
            ladder[y][x] = true;
            if (back_tracking(y, x + 1, depth + 1))
                return (true);
            ladder[y][x] = false;
        }

        ++x;
    }
    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int y, x;
    int linkCnt;

    std::cin >> xSize >> linkCnt >> ySize;
    while (linkCnt--)
    {
        std::cin >> y >> x;
        ladder[y][x] = true;
    }

    while (limit <= 3)
    {
        if (back_tracking())
        {
            std::cout << limit << '\n';
            return (0);
        }
        ++limit;
    }

    std::cout << -1 << '\n';
    return (0);
}
