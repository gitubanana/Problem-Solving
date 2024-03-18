#include <iostream>
#include <algorithm>

const int MAX = 9;

int limit;
char str[MAX * 2];

inline void fill1To9(void)
{
    int idx = 0;

    for (char toPut = '1'; toPut <= '9'; ++toPut)
    {
        str[idx] = toPut;
        idx += 2;
    }
}

int getNum(int &i)
{
    int ret = 0;

    while (str[i] == ' ' || std::isdigit(str[i]))
    {
        if (str[i] != ' ')
            ret = ret * 10 + (str[i] - '0');
        ++i;
    }
    return ret;
}

int calculate(int size)
{
    int i = 0;
    int cur = getNum(i);

    while (i < size)
    {
        int operPos = i++;
        int num = getNum(i);

        switch (str[operPos]) {
            case '+':
                cur += num;
                break ;
            case '-':
                cur -= num;
        }
    }
    return cur;
}

void back_tracking(int depth=1)
{
    static const char opers[] = {' ', '+', '-'};
    static const int operSize = sizeof(opers) / sizeof(opers[0]);

    if (depth == limit)
    {
        if (calculate(depth * 2) == 0)
            std::cout << str << '\n';
        return ;
    }

    int operPos = depth * 2 - 1;
    for (int i = 0; i < operSize; ++i)
    {
        str[operPos] = opers[i];
        back_tracking(depth + 1);
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    std::cin >> testCnt;

    fill1To9();
    while (testCnt--)
    {
        std::cin >> limit;
        int nullPos = limit * 2;

        str[nullPos] = 0;
        back_tracking();
        str[nullPos] = limit + '1';
        std::cout << '\n';
    }
    return 0;
}
