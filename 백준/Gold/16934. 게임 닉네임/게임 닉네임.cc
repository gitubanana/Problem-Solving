#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>

const int SIZE = 10;

struct t_trie
{
    std::unordered_map<char, std::shared_ptr<t_trie>> umap;
    int used;
    bool passed;

    t_trie() : used(0), passed(false) { }
};

using p_trie = std::shared_ptr<t_trie>;

p_trie root(new t_trie());

std::string getNickName(const std::string &name)
{
    std::string nickName;
    p_trie cur = root;
    bool completed = false;

    for (const char &ch : name)
    {
        p_trie &next = cur->umap[ch];
        if (next == NULL)
        {
            next = p_trie(new t_trie());
        }

        cur = next;
        if (!completed)
        {
            nickName += ch;
            if (!cur->passed)
            {
                completed = true;
            }
        }

        cur->passed = true;
    }

    ++cur->used;
    if (!completed && cur->used > 1)
    {
        nickName += std::to_string(cur->used);
    }

    return (nickName);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int nameCnt;

    std::cin >> nameCnt;
    while (nameCnt--)
    {
        std::string name;

        std::cin >> name;
        std::cout << getNickName(name) << '\n';
    }
    return (0);
}
