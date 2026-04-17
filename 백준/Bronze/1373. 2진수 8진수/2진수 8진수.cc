#include <iostream>
#include <deque>

int main()
{
    int         i, cal_idx, num;
    std::string binary_str;
    std::deque<int> octal_num;

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> binary_str;
    i = binary_str.size() - 1;
    for (; i >= 0; i -= 3)
    {
        num = 0;
        for (cal_idx = i - 2; cal_idx <= i; ++cal_idx)
        {
            if (cal_idx < 0)
                continue ;
            num = num * 2 + (binary_str[cal_idx] - '0');
        }
        octal_num.push_front(num);
    }
    for (i = 0; i < octal_num.size(); ++i)
        std::cout << octal_num[i];
    std::cout << '\n';
    return 0;
}
