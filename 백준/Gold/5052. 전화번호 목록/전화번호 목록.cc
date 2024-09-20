#include <iostream>
#include <algorithm>
#include <vector>

const int SIZE = 10;

struct t_trie
{
    bool isOccupied;
    std::vector<t_trie> arr;

    t_trie() : isOccupied(false) { }
};

struct Comp
{
    inline bool operator()(const std::string &a, const std::string &b) const
    {
        return (a.size() < b.size());
    }
};

bool    addTrie(t_trie &trie, const std::string &num, int depth=0)
{
    const int curIdx = num[depth] - '0';
    if (trie.arr.empty())
    {
        trie.arr.resize(SIZE);
    }

    t_trie &curTrie = trie.arr[curIdx];
    bool &isOccupied = curTrie.isOccupied;
    if (isOccupied)
    {
        return (false);
    }

    if (num[depth + 1] == '\0')
    {
        isOccupied = true;
        return (true);
    }

    return addTrie(curTrie, num, depth + 1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    const char *msg[] = {"NO", "YES"};
    std::string num;
    std::vector<std::string> nums;

    std::cin >> testCnt;
    while (testCnt--)
    {
        int numCnt;
        t_trie root;

        nums.clear();
        std::cin >> numCnt;
        while (numCnt--)
        {
            std::cin >> num;
            nums.push_back(num);
        }

        bool isConsistent = true;

        std::sort(nums.begin(), nums.end(), Comp());
        for (const std::string &num : nums)
        {
            if (!addTrie(root, num))
            {
                isConsistent = false;
                break ;
            }
        }

        std::cout << msg[isConsistent] << '\n';
    }
    return (0);
}
