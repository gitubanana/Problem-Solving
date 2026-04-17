#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

int64_t    ans = LONG_LONG_MAX;

void    find_square_root(int64_t n)
{
        int64_t left, right, mid;

    left = 0;
    right = n;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (static_cast<double>(mid) * mid >= n)
        {
            ans = std::min(ans, mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
}

int main()
{
    int64_t    n;

    scanf(" %ld", &n);
        if (n <= 1)
                ans = n;
        else
                find_square_root(n);
    printf("%ld\n", ans);
    return 0;
}