#include <iostream>

int     cnt[10];

bool    is_multiple_of_30(std::string &num_str)
{
        int     i;
        int     num;
        int     sum = 0;

        for (i = 0; num_str[i]; ++i)
        {
                num = num_str[i] - '0';
                ++cnt[num];
                sum += num;
        }
        return (sum % 3 == 0 && cnt[0]);
}

void    print_max_30(std::string &num_str)
{
        if (!is_multiple_of_30(num_str))
        {
                std::cout << "-1" << '\n';
                return ;
        }
        for (int i = 9; i >= 0; --i)
                while (cnt[i]--)
                        std::cout << i;
        std::cout << '\n';
}

int     main(void)
{
        std::ios::sync_with_stdio(0), std::cin.tie(0);

        std::string     num_str;

        std::cin >> num_str;
        print_max_30(num_str);
        return (0);
}