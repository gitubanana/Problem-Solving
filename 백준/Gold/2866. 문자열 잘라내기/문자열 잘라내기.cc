#include <iostream>
#include <unordered_set>

using t_uset = std::unordered_set<std::string>;

const int MAX_SIZE = 1000;

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> xSize >> ySize;
    for (int x = 0; x < xSize; ++x)
    {
        for (int y = 0; y < ySize; ++y)
        {
            std::cin >> map[y][x];
        }
    }

    int startX = 1;
    while (true)
    {
        t_uset uset;

        for (int y = 0; y < ySize; ++y)
        {
            if (uset.find(&map[y][startX]) != uset.end())
            {
                std::cout << startX - 1 << '\n';
                return (0);
            }
            else
            {
                uset.insert(&map[y][startX]);
            }
        }

        ++startX;
    }

    return (0);
}
