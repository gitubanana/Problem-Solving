#include <iostream>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        int curAtMost = 1;
        int importTurtle = 0;

        while (true)
        {
            int curNum;

            std::cin >> curNum;
            if (curNum == 0)
                break ;

            if (curAtMost < curNum)
            {
                importTurtle += curNum - curAtMost;
            }

            curAtMost = curNum;
            curAtMost <<= 1;
        }

        std::cout << importTurtle << '\n';
    }
    return (0);
}
