#include <iostream>

void    print_ans(std::string *strs, int size)
{
        std::string &to_print = strs[0];

        int     str_idx, cmp_idx;

        for (str_idx = 1; str_idx < size; ++str_idx)
        {
                std::string     &cmp_str = strs[str_idx];
                for (cmp_idx = 0; to_print[cmp_idx]; ++cmp_idx)
                {
                        if (cmp_str[cmp_idx] != to_print[cmp_idx])
                                to_print[cmp_idx] = '?';
                }
        }

        std::cout << to_print << '\n';
}

int     main(void)
{
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);

        int     size;
        std::string     *strs;

        std::cin >> size;
        strs = new std::string[size];
        for (int i = 0; i < size; ++i)
                std::cin >> strs[i];

        print_ans(strs, size);

        delete[] strs;
        return (0);
}