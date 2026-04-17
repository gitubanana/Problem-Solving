#include <iostream>
#include <algorithm>

int    main(void)
{
    std::string str;
        std::string     *strs;

    std::cin >> str;

    strs = new std::string[str.size()];
    for (int i = 0; str[i]; ++i)
        strs[i] = std::string(&str[i]);

    std::sort(strs, strs + str.size());
    for (int i = 0; str[i]; ++i)
    {
        std::cout << strs[i] << '\n';
    }
    delete[] strs;
    return (0);
}