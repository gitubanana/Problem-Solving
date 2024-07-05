#include <iostream>
#include <iomanip>
#include <unordered_map>

using t_monthMap = std::unordered_map<std::string, int>;

const int DAY_TO_MIN = 60 * 24;
t_monthMap monthMap({
    {"January", 1},
    {"February", 2},
    {"March", 3},
    {"April", 4},
    {"May", 5},
    {"June", 6},
    {"July", 7},
    {"August", 8},
    {"September", 9},
    {"October", 10},
    {"November", 11},
    {"December", 12}
});
int monthDays[] = {
    0,
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
};

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    char comma;
    int day, year;
    std::string month;
    std::string hourAndMin;

    std::cin >> month >> day >> comma >> year >> hourAndMin;

    const int hour = std::atoi(&hourAndMin[0]);
    const int minute = std::atoi(&hourAndMin[3]);
    const int &curMonth = monthMap[month];
    double totalMinute = 0;
    double curMinute = (day - 1) * DAY_TO_MIN + hour * 60 + minute;

    monthDays[2] += (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
    for (int m = 1; m <= 12; ++m)
    {
        int addMin = monthDays[m] * DAY_TO_MIN;

        totalMinute += addMin;
        if (m < curMonth)
        {
            curMinute += addMin;
        }
    }

    std::cout << std::fixed << std::setprecision(10) << curMinute * 100 / totalMinute << '\n';
    return (0);
}
