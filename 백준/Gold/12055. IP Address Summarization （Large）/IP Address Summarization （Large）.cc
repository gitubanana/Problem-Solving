#include <iostream>
#include <memory>
#include <vector>
#include <map>

const uint ALL_ONE = -1;
const uint FIRST_ONE = (1 << 31);
const int EIGHT_ONE = (1 << 8) - 1;

struct t_trie
{
    std::shared_ptr<t_trie> next[2];
    bool isIp;
    bool partOfIp;

    t_trie() : isIp(false), partOfIp(false) { }
};

using p_trie = std::shared_ptr<t_trie>;

void    addTrie(p_trie &root, int ip, int prefix)
{
    p_trie cur = root;

    while (prefix--)
    {
        bool bit = ip & FIRST_ONE;
        p_trie &next = cur->next[bit];
        if (next == NULL)
        {
            next = p_trie(new t_trie());
        }

        cur = next;
        if (cur->isIp)
        {
            return ;
        }

        ip <<= 1;
    }

    cur->isIp = true;
}

void    mergeIp(p_trie &cur)
{
    p_trie &nextZero = cur->next[0];
    p_trie &nextOne = cur->next[1];

    if (nextZero != NULL)
    {
        mergeIp(nextZero);
    }

    if (nextOne != NULL)
    {
        mergeIp(nextOne);
    }

    if ((nextZero != NULL && nextZero->isIp)
        && (nextOne != NULL && nextOne->isIp))
    {
        cur->isIp = true;
    }
}

void    printIp(int curBit, int prefix)
{
    for (int i = 3; i >= 0; --i)
    {
        printf("%d", curBit >> (8 * i) & EIGHT_ONE);
        if (i != 0)
        {
            printf(".");
        }
    }

    printf("/%d\n", prefix);
}

void    printTrie(p_trie &cur, int curBit=0, int shift=31)
{
    if (cur->isIp)
    {
        int prefix = 32 - (shift + 1);

        printIp(curBit << (shift + 1), prefix);
        return ;
    }

    p_trie &nextZero = cur->next[0];
    p_trie &nextOne = cur->next[1];

    if (nextZero != NULL)
    {
        printTrie(
            nextZero,
            (curBit << 1),
            shift - 1
        );
    }

    if (nextOne != NULL)
    {
        printTrie(
            nextOne,
            (curBit << 1) | 1,
            shift - 1
        );
    }
}

int main(void)
{
    int testCnt;

    scanf(" %d", &testCnt);
    for (int t = 1; t <= testCnt; ++t)
    {
        p_trie root(new t_trie());
        int subnetCnt;

        scanf(" %d", &subnetCnt);
        while (subnetCnt--)
        {
            int a, b, c, d, prefix;
            scanf(" %d.%d.%d.%d/%d", &a, &b, &c, &d, &prefix);

            int ip = (a << 24) | (b << 16) | (c << 8) | d;
            addTrie(root, ip, prefix);
        }

        printf("Case #%d:\n", t);
        mergeIp(root);
        printTrie(root);
    }
    return (0);
}
