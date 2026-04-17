#include <iostream>

int cnt[2];
const char  REMOVED = 'R';

void    print_ans(std::string &str)
{
    int i = 0;

    for (; str[i]; ++i)
        ++cnt[str[i] - '0'];

    for (i = 0; i < 2; ++i)
        cnt[i] /= 2;

    while (true)
    {
        if (cnt[0]-- > 0)
            str[str.find_last_of('0')] = REMOVED;
        else if (cnt[1]-- > 0)
            str[str.find('1')] = REMOVED;
        else
            break ;
    }

    for (i = 0; str[i]; ++i)
        if (str[i] != REMOVED)
            std::cout << str[i];
    std::cout << '\n';
}

int main(void)
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string str;

    std::cin >> str;
    print_ans(str);
    return 0;
}
