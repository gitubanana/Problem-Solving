#include <iostream>

const int    MAX = 5;

int    main(void)
{
    int            y, x, is_printed;
    std::string    str[MAX];
    
    for (y = 0; y < MAX; ++y)
        std::cin >> str[y];
    for (x = 0; true; ++x)
    {
        is_printed = 0;
        for (y = 0; y < MAX; ++y)
        {
            if (!(x < str[y].size()))
                continue ;
            is_printed = printf("%c", str[y][x]);
        }
        if (!is_printed)
            break ;
    }
    return (0);
}