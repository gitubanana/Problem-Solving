#include <iostream>

const int MAX_SIZE = 10;
const int DIAGONAL_TYPE = 2;

int size;
bool isLeftUp;
int placeCnt[2];
bool occupied[2][MAX_SIZE * 2 - 3];
bool canPlace[MAX_SIZE][MAX_SIZE];

void    backTracking(int y, int x, int cnt=0)
{
    placeCnt[isLeftUp] = std::max(
        placeCnt[isLeftUp],
        cnt
    );

    if (x >= size)
    {
        x = (++y & 1) ^ isLeftUp;

        if (y >= size)
        {
            return ;
        }
    }

    backTracking(y, x + 2, cnt);
    if (canPlace[y][x])
    {
        bool &leftUp = occupied[0][y + x];
        bool &rightDown = occupied[1][y - x + size];

        if (!leftUp && !rightDown)
        {
            leftUp = rightDown = true;
            backTracking(y, x + 2, cnt + 1);
            leftUp = rightDown = false;
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
        {
            std::cin >> canPlace[y][x];
        }
    }

    int ans = 0;
    for (int i = 0; i < DIAGONAL_TYPE; ++i)
    {
        isLeftUp = i;
        backTracking(0, i);
        ans += placeCnt[i];
    }

    std::cout << ans << '\n';
    return (0);
}
