#include <iostream>
#include <unordered_map>

using t_nummap = std::unordered_map<std::string, int>;

t_nummap numMap({
    {"####.##.##.####", 0},
    {"#####", 1},
    {"###..#####..###", 2},
    {"###..####..####", 3},
    {"#.##.####..#..#", 4},
    {"####..###..####", 5},
    {"####..####.####", 6},
    {"###..#..#..#..#", 7},
    {"####.#####.####", 8},
    {"####.####..####", 9}
});


int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    std::string signal;

    std::cin >> size >> signal;
    size /= 5;

    if (size == 1)
    {
        std::cout << 1 << '\n';
        return (0);
    }

    for (int x = 0; x < size; ++x)
    {
        if (signal[x] == '.')
            continue ;

        int addSize = (
            (signal.compare(x, 3, "###") != 0
             && signal.compare(size * 2 + x, 3, "###") != 0)
            ? 1
            : 3
        );

        std::string signum = signal.substr(x, addSize);

        for (int y = size; y < signal.size(); y += size)
        {
            signum += signal.substr(y + x, addSize);
        }

        std::cout << numMap[signum];
        x += addSize;
    }
    std::cout << '\n';

    return (0);
}
