#include <iostream>

const int MAX_SIZE = 100;
const int EMPTY = 0;

int stackSize;
int top[MAX_SIZE];

inline bool isDecreasing(int num)
{
    bool ret = false;

    for (int i = 0; i < stackSize; ++i)
    {
        int &curTop = top[i];

        if (curTop == EMPTY || curTop < num)
        {
            curTop = num;
            ret = true;
            break ;
        }
    }

    return (ret);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt;
    bool isOk = true;
    const char *msg[] = {"NO", "YES"};

    std::cin >> vCnt >> stackSize;
    while (vCnt--)
    {
        int cur;

        std::cin >> cur;
        if (!isDecreasing(cur))
        {
            isOk = false;
            break ;
        }
    }

    std::cout << msg[isOk] << '\n';
    return (0);
}
