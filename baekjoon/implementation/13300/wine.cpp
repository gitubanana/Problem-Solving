#include <iostream>

struct t_class
{
    int studentCnt[2];
};

const int MAX = 6;

t_class arr[MAX + 1];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int roomSize;
    int studentCnt;
    int class_, gender;

    std::cin >> studentCnt >> roomSize;
    while (studentCnt--)
    {
        std::cin >> gender >> class_;
        ++arr[class_].studentCnt[gender];
    }

    int ans = 0;
    for (int i = 1; i <= MAX; ++i)
    {
        t_class &curClass = arr[i];

        for (int gender = 0; gender <= 1; ++gender)
            ans += (curClass.studentCnt[gender] / roomSize) + (curClass.studentCnt[gender] % roomSize != 0);
    }

    std::cout << ans << '\n';
    return (0);
}
