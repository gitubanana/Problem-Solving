#include <iostream>
#include <deque>
#include <algorithm>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size, toFindCnt;
    std::deque<int> deque;

    std::cin >> size >> toFindCnt;
    for (int i = 1; i <= size; ++i)
        deque.push_back(i);

    int toFind;
    int ans = 0;
    while (toFindCnt--)
    {
        std::cin >> toFind;

        int idx = std::find(deque.begin(), deque.end(), toFind) - deque.begin();
        if (idx <= deque.size() / 2)
        {
            ans += idx;
            while (idx--)
            {
                int popped = deque.front();

                deque.pop_front();
                deque.push_back(popped);
            }
        }
        else
        {
            idx = deque.size() - idx;
            ans += idx;
            while (idx--)
            {
                int popped = deque.back();

                deque.pop_back();
                deque.push_front(popped);
            }
        }
        deque.pop_front();
    }

    std::cout << ans << '\n';
    return (0);
}
