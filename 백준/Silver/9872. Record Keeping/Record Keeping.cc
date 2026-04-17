#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>

typedef std::map<std::string, int>  t_map;

int main(void)
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    t_map       _map;
    std::string cows[3];
    int         size, max;
    t_map::iterator iter;

    std::cin >> size;
    max = 1;
    while (size--)
    {
        std::cin >> cows[0] >> cows[1] >> cows[2];
        std::sort(cows, cows + 3);
        cows[0] += cows[1];
        cows[0] += cows[2];
        iter = _map.find(cows[0]);
        if (iter != _map.end())
        {
            ++iter->second;
            max = std::max(max, iter->second);
        }
        else
            _map.insert({cows[0], 1});
    }

    std::cout << max << '\n';
    return 0;
}
