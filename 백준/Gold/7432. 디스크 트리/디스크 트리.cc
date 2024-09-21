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

void    printTunnel(p_trie &cur, int space=0)
{
    for (std::pair<const std::string, p_trie> &next : cur->map)
    {
        for (int i = 0; i < space; ++i)
        {
            std::cout << ' ';
        }

        std::cout << next.first << '\n';
        printTunnel(next.second, space + 1);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int infoCnt;

    std::cin >> infoCnt;
    while (infoCnt--)
    {
        std::string path;
        std::cin >> path;

        int s = 0;
        int pathSize = path.size();
        p_trie cur = root;
        while (s < pathSize)
        {
            int e = path.find_first_of('\\', s + 1);
            if (e == std::string::npos)
            {
                e = pathSize;
            }

            std::string file = path.substr(s, e - s);
            p_trie &next = cur->map[file];
            if (next == NULL)
            {
                next = p_trie(new t_trie());
            }

            cur = next;
            s = e + 1;
        }
    }

    printTunnel(root);
    return (0);
}
