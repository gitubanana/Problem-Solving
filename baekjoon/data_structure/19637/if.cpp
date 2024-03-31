#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

const int MAX = 1e5;

typedef std::map<int, std::string> t_map;

t_map _map;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int tierSize, findCnt;
    int strength;
    std::string tier;

    std::cin >> tierSize >> findCnt;
    while (tierSize--)
    {
        std::cin >> tier >> strength;

        t_map::iterator it = _map.find(strength);

        if (it == _map.end())
        {
            _map[strength] = tier;
        }
    }

    while (findCnt--)
    {
        std::cin >> strength;

        std::cout << _map.lower_bound(strength)->second << '\n';
    }
    return (0);
}
