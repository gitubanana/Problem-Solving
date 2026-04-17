#include <iostream>

const char  OFFSET = 'A';
const int   MAX = 26;

int cnt[MAX];

bool    can_make_palindrome(int str_size)
{
    int i = 0;
    int odd_cnt = 0;
    int odd_idx = -1;
    std::string half_front;

    for (; i < MAX; ++i)
        if (cnt[i] & 1)
            ++odd_cnt, odd_idx = i;

    if (str_size & 1)
    {
        if (odd_cnt != 1)
            return (false);
    }
    else if (odd_cnt != 0)
        return (false);

    for (i = 0; i < MAX; ++i)
    {
        while (cnt[i] > 1)
        {
            half_front += (i + OFFSET);
            cnt[i] -= 2;
        }
    }
    std::cout << half_front;
    if (odd_idx != -1)
        std::cout << static_cast<char>(odd_idx + OFFSET);
    for (i = half_front.size() - 1; i >= 0; --i)
        std::cout << half_front[i];
    return (true);
}

void    print_ans(std::string &str)
{
    int i;
    std::string present;

    for (i = 0; str[i]; ++i)
        ++cnt[str[i] - OFFSET];

    if (!can_make_palindrome(str.size()))
        std::cout << "I'm Sorry Hansoo";
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
