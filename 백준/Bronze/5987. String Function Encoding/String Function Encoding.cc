#include <iostream>

void    encode(std::string &str, size_t idx)
{
    str = str.substr(idx, str.size() - idx) + str;
}

int    main(void)
{
    int    test_cnt;
    std::string    str;
    size_t    func_cnt, idx;

    std::cin >> test_cnt;
    while (test_cnt)
    {
        std::cin >> idx >> func_cnt >> str;
        while (func_cnt)
        {
            encode(str, idx);
            --func_cnt;
        }
        std::cout << str << '\n';
        --test_cnt;
    }
    return (0);
}