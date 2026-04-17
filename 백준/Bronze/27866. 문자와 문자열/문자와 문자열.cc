#include <iostream>

int    main(void)
{
    int            idx_plus_1;
    std::string    str;
    
    std::cin >> str >> idx_plus_1;
    std::cout << str[idx_plus_1 - 1] << std::endl;
    return (0);
}