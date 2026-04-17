#include <iostream>
#include <cmath>

// 1     -> (2 3)        -> (4 5 6)             -> (7 8 9 10)
// (1/1) -> (1/2 -> 2/1) -> (3/1 -> 2/2 -> 1/3) -> (1/4 -> 2/3 -> 3/2 -> 4/1);

int main(void)
{
    int sum;
    int n, i, idx;
    int group_num;

    scanf(" %d", &n);
    if (n == 1)
        return !(std::cout << "1/1" << std::endl);

    idx = n;
    sum = group_num = 0;
    i = 1;
    while (1)
    {
        ++group_num;
        sum += i;
        if (sum >= n)
            break ;
        idx -= i;
        ++i;
    }

    // group_num이 홀수
    if (group_num & 1)
        std::cout << (group_num - idx + 1) << "/" << idx << std::endl;
    else
        std::cout << idx << "/" << (group_num - idx + 1) << std::endl;
    return (0);
}
