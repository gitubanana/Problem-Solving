#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>

struct t_trie
{
    std::unordered_map<std::string, std::shared_ptr<t_trie>> umap;
};

using p_trie = std::shared_ptr<t_trie>;

int    addTrie(p_trie &root, std::string &dir)
{
    p_trie cur = root;
    int s = 1;
    int mkdirCnt = 0;
    int dirSize = dir.size();

    while (s < dirSize)
    {
        int e = dir.find_first_of('/', s + 1);
        if (e == std::string::npos)
        {
            e = dirSize;
        }

        dir[e] = 0;
        p_trie &next = cur->umap[&dir[s]];
        if (next == NULL)
        {
            next = p_trie(new t_trie());
            ++mkdirCnt;
        }

        cur = next;
        s = e + 1;
    }

    return (mkdirCnt);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    int existCnt, makeCnt;
    std::string dir;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        p_trie root(new t_trie());

        std::cin >> existCnt >> makeCnt;
        while (existCnt--)
        {
            std::cin >> dir;
            addTrie(root, dir);
        }

        int mkdirCnt = 0;
        while (makeCnt--)
        {
            std::cin >> dir;
            mkdirCnt += addTrie(root, dir);
        }

        std::cout << "Case #" << t << ": " << mkdirCnt << '\n';
    }

    return (0);
}

