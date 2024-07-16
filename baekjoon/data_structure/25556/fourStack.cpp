#include <iostream>
#include <stack>

const int STACK_CNT = 4;
const int EMPTY = 0;

int top[STACK_CNT];

inline bool pushDecreasingly(int num)
{
    for (int i = 0; i < STACK_CNT; ++i)
    {
        int &curTop = top[i];

        if (!(curTop == EMPTY || curTop < num))
            continue ;

        curTop = num;
        return (true);
    }

    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;

    std::cin >> size;
    while (size--)
    {
        int num;

        std::cin >> num;
        if (!pushDecreasingly(num))
        {
            std::cout << "NO" << '\n';
            return (0);
        }
    }

    std::cout << "YES" << '\n';
    return (0);
}
