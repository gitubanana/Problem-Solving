#include <iostream>

int    main(void)
{
    char    prev_ch;
    char    str[251];

    scanf(" %s", str);
    prev_ch = 0;
    for (int i = 0; str[i]; ++i)
    {
        if (prev_ch == str[i])
            continue ;
        std::cout << str[i];
        prev_ch = str[i];
    }
    std::cout << '\n';
    return (0);
}