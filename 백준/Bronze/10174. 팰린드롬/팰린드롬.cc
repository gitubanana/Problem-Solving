#include <iostream>

bool    is_panlindrome(std::string &str)
{
    int half_size = str.size() / 2;

    for (int i = 0; i < half_size; ++i)
    {
        if (str[i] != str[str.size() - i - 1])
            return (false);
    }
    return (true);
}

int    main(void)
{
    char    new_line;
    std::string    str;
    int            test_cnt;

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> test_cnt;
    std::getline(std::cin, str);
    while (test_cnt)
    {
        std::getline(std::cin, str);
        for (char &ch : str)
            ch = std::toupper(ch);
        if (is_panlindrome(str))
            std::cout << "Yes";
        else
            std::cout << "No";
        std::cout << '\n';
        --test_cnt;
    }
    return (0);
}