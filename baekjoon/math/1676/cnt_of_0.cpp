#include <iostream>
#include <set>

// n   : 5, 10, 15, 20, * 25 *, 30, 35, 40, 45, 50
// cnt : 1,  2,  3,  4, *  6 *,  7,  8,  9, 10, 12

int main(void)
{
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int n;
    int ans = 0;
    int arr[] = {5, 25, 125};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cin >> n;
    for (int i = 0; i < size; ++i)
    {
        ans += n / arr[i];
    }
    std::cout << ans << '\n';
    return (0);
}
