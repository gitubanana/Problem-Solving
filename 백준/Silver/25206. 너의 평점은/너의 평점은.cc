#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>

std::pair<std::string, double>    credit[] = {
    {"A+", 4.5}, {"A0", 4.0},
    {"B+", 3.5}, {"B0", 3.0},
    {"C+", 2.5}, {"C0", 2.0},
    {"D+", 1.5}, {"D0", 1.0}};

std::map<std::string, double>    _map(credit,
                                      credit + sizeof(credit) / sizeof(credit[0]));

int     CNT = 20;

int    main(void)
{
        std::string     subject;
        std::string     grade_str;
        double          grade;
        double          sum;
        int                     divisor;

        sum = divisor = 0;
        while (CNT--)
        {
                std::cin >> subject >> grade >> grade_str;
                if (grade_str == "P")
                        continue ;
                sum += _map[grade_str] * grade;
                divisor += grade;
        }
        std::cout << std::setprecision(6) << std::fixed << sum / divisor << '\n';
        return (0);
}