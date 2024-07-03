#include <iostream>
#include <algorithm>
#include <vector>

const int MAX_SIZE = 10;
const int BEE_CNT = 2;

int maxMoney, plusMoney;
int size, honeyCnt, honeyLimit;
char map[MAX_SIZE][MAX_SIZE];

void    findMaxMoney(char *cur, char *end, int curHoney=0, int curMoney=0)
{
    if (curHoney > honeyLimit)
        return ;

    plusMoney = std::max(plusMoney, curMoney);
    while (cur != end)
    {
        int toAdd = *cur++;

        findMaxMoney(
            cur,
            end,
            curHoney + toAdd,
            curMoney + toAdd * toAdd
        );
    }
}

void    backTracking(int y=0, int x=0, int curMoney=0, int depth=0)
{
    if (depth == BEE_CNT)
    {
        maxMoney = std::max(maxMoney, curMoney);
        return ;
    }

    while (true)
    {
        if (x + honeyCnt > size)
        {
            x = 0;
            ++y;
            if (y == size)
                break ;
        }

        plusMoney = 0;
        findMaxMoney(map[y] + x, map[y] + x + honeyCnt);
        backTracking(y, x + honeyCnt, curMoney + plusMoney, depth + 1);

        ++x;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        std::cin >> size >> honeyCnt >> honeyLimit;
        for (int y = 0; y < size; ++y)
        {
            for (int x = 0; x < size; ++x)
            {
                char &curSpace = map[y][x];

                std::cin >> curSpace;
                curSpace -= '0';
            }
        }

        maxMoney = 0;
        backTracking();
        std::cout << '#' << t << ' ' << maxMoney << '\n';
    }
    return (0);
}
