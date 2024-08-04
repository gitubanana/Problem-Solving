#include <iostream>
#include <cmath>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::string str;
    std::cin >> str;

    int ySize = sqrt(str.size());
    for (; ySize >= 1; --ySize)
    {
        if (str.size() % ySize == 0)
        {
            break ;
        }
    }

    int xSize = str.size() / ySize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cout << str[y + x * ySize];
        }
    }
    std::cout << '\n';
    return (0);
}
