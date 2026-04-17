#include <iostream>

int    main(void)
{
    std::string    str;
    int            test_cnt;
    int            i, is_present, sum;

    std::cin >> test_cnt;
    while (test_cnt)
    {
        std::cin >> str;
        is_present = 0;
        for (i = 0; i < str.size(); ++i)
        {
            is_present |= (1 << (str[i] - 'A'));
        }
        sum = 0;
        for (i = 0; i < 26; ++i)
        {
            if (!(is_present & (1 << i)))
                sum += i + 'A';
        }
        std::cout << sum << '\n';
        --test_cnt;
    }
    return (0);
}