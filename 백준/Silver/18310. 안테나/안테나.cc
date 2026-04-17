#include <iostream>
#include <algorithm>
#include <climits>

const int MAX = 200000;

int size;
int homes[MAX];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int i = 0; i < size; ++i)
        std::cin >> homes[i];

    if (size == 1)
    {
        std::cout << homes[0] << '\n';
        return (0);
    }

    std::sort(homes, homes + size);

    std::cout << (size & 1 ? homes[size / 2] : homes[size / 2 - 1]) << '\n';
    return (0);
}
