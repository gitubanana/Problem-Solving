#include <iostream>

int n;
int curCnt = 1022;
int digit = 10;
char str[11];

void findD(char num, int depth)
{
    if (depth == digit)
    {
        if (curCnt == n)
        {
            str[depth] = 0;
            std::cout << str << '\n';
            exit(0);
        }
        --curCnt;
        return ;
    }

    while (num >= '0')
    {
        str[depth] = num;
        findD(--num, depth + 1);
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (; digit >= 1; --digit)
    {
        findD('9', 0);
    }

    std::cout << -1 << '\n';
    return 0;
}
