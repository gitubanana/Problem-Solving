#include <iostream>

int main(void)
{
    int          total_days;
    int          month, date;
    std::string  day;
    const int    arr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    scanf(" %d %d", &month, &date);
    total_days = date;
    for (int start = 1; start < month; start++)
        total_days += arr[start - 1];
    switch (total_days % 7)
    {
        case 1:
            day = "MON";
            break ;
        case 2:
            day = "TUE";
            break ;
        case 3:
            day = "WED";
            break ;
        case 4:
            day = "THU";
            break ;
        case 5:
            day = "FRI";
            break ;
        case 6:
            day = "SAT";
            break ;
        default:
            day = "SUN";
    }
    std::cout << day << std::endl;
    return 0;
}