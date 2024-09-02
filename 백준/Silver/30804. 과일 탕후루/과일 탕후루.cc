#include <iostream>
#include <deque>

const int CANDY_TYPE = 9 + 1;

int cnt[CANDY_TYPE];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int candyCnt;
    int typeCnt = 0;
    size_t maxCandy = 0;
    std::deque<int> q;

    std::cin >> candyCnt;
    while (candyCnt--)
    {
        int type;

        std::cin >> type;
        typeCnt += (cnt[type]++ == 0);
        q.push_back(type);
        while (typeCnt > 2)
        {
            int pop = q.front();
            q.pop_front();

            typeCnt -= (--cnt[pop] == 0);
        }

        maxCandy = std::max(maxCandy, q.size());
    }

    std::cout << maxCandy << '\n';
    return (0);
}
