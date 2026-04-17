#include <iostream>
#include <climits>
#include <cstdio>
#include <algorithm>

long long min = LONG_LONG_MAX;

long long win_rate(long long total, long long win)
{
    return (100 * static_cast<double>(win) / total);
}

void    parametric_search(long long total, long long win)
{
    long long left, right, mid;
    long long origin = win_rate(total, win);

    left = 1;
    right = total;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (win_rate(total + mid, win + mid) > origin)
        {
            min = std::min(min, mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
}

int main()
{
    long long total, win;

    scanf(" %ld %ld", &total, &win);
    parametric_search(total, win);
    if (min == LONG_LONG_MAX)
        min = -1;
    printf("%ld\n", min);
    return 0;
}