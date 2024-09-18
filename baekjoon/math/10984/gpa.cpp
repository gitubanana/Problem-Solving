#include <iostream>
#include <iomanip>

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        int calCnt;
        int sum = 0;
        double gpa = 0;

        std::cin >> calCnt;
        for (int i = 0; i < calCnt; ++i)
        {
            int score;
            double grade;

            std::cin >> score >> grade;
            sum += score;
            gpa += grade * score;
        }

        std::cout << sum << ' ' << std::fixed << std::setprecision(1) << gpa / sum << '\n';
    }
    return 0;
}
