#include <iostream>
#include <memory>
#include <vector>
#include <map>

const int SIZE = 10;

struct t_trie
{
    std::map<std::string, std::shared_ptr<t_trie>> map;
};

using p_trie = std::shared_ptr<t_trie>;

p_trie root(new t_trie());

void    printTunnel(p_trie &cur, int bar=0)
{
    for (std::pair<const std::string, p_trie> &next : cur->map)
    {
        for (int i = 0; i < bar; ++i)
        {
            std::cout << "--";
        }

        std::cout << next.first << '\n';
        printTunnel(next.second, bar + 1);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int infoCnt;

    std::cin >> infoCnt;
    while (infoCnt--)
    {
        int floorCnt;
        std::string name;
        p_trie cur = root;

        std::cin >> floorCnt;
        while (floorCnt--)
        {
            std::cin >> name;
            if (cur->map[name] == NULL)
            {
                cur->map[name] = p_trie(new t_trie());
            }

            cur = cur->map[name];
        }
    }

    printTunnel(root);
    return (0);
}
