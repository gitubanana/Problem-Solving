#include <iostream>

const int MAX = 101;

bool map[MAX][MAX];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int leftDownX, leftDownY;
    int rightUpX, rightUpY;

    for (int i = 0; i < 4; ++i)
    {
        std::cin >> leftDownX >> leftDownY;
        std::cin >> rightUpX >> rightUpY;

        for (int y = leftDownY; y < rightUpY; ++y)
        {
            for (int x = leftDownX; x < rightUpX; ++x)
            {
                map[y][x] = true;
            }
        }
    }

    int ans = 0;
    for (int y = 0; y < MAX; ++y)
    {
        for (int x = 0; x < MAX; ++x)
        {
            ans += map[y][x];
        }
    }

    std::cout << ans << '\n';
    return (0);
}
