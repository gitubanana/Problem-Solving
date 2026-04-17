#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>

std::pair<std::string, double>    credit[] = {
    {"A+", 4.3}, {"A0", 4.0}, {"A-", 3.7},
    {"B+", 3.3}, {"B0", 3.0}, {"B-", 2.7},
    {"C+", 2.3}, {"C0", 2.0}, {"C-", 1.7},
    {"D+", 1.3}, {"D0", 1.0}, {"D-", 0.7}};

std::map<std::string, double>    _map(credit,
                                      credit + sizeof(credit) / sizeof(credit[0]));

int    main(void)
{
    std::string    str;

    std::cin >> str;
    std::cout << std::setprecision(1) << std::fixed <<_map[str] << '\n';
    return (0);
}