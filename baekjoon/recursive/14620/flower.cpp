#include <iostream>
#include <algorithm>

const int MAX = 10;
const int LIMIT = 3;
const int NOT_AVAILABLE = -1;
int land[MAX][MAX];
bool isFlower[MAX][MAX];
int seedSize;
int size, min = 1e9;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int getLandPrice(int y, int x)
{
    int ret = land[y][x];

    for (int i = 0; i < 4; ++i)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (isFlower[nextY][nextX])
            return NOT_AVAILABLE;

        ret += land[nextY][nextX];
    }
    return (ret);
}

void    setFlower(int y, int x, bool isFlowerValue)
{
    isFlower[y][x] = isFlowerValue;
    for (int i = 0; i < 4; ++i)
        isFlower[y + dy[i]][x + dx[i]] = isFlowerValue;
}

void    back_tracking(int curY, int curX, int totalPrice, int depth)
{
    if (depth == LIMIT)
    {
        min = std::min(min, totalPrice);
        return ;
    }


    for (int y = 1; y < seedSize; ++y)
    {
        for (int x = 1; x < seedSize; ++x)
        {
            int landPrice = getLandPrice(y, x);
            if (landPrice != NOT_AVAILABLE)
            {
                setFlower(y, x, true);
                back_tracking(y, x, totalPrice + landPrice, depth + 1);
                setFlower(y, x, false);
            }
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
            std::cin >> land[y][x];
    }

    seedSize = size - 1;
    back_tracking(1, 1, 0, 0);

    std::cout << min << '\n';
    return (0);
}
