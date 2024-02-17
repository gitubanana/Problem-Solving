#include <iostream>
#include <algorithm>

const int MAX = 2000;

int size;
int arr[MAX];
int dp[MAX];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    for (int i = 0; i < size; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] < arr[j])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    std::cout << size - *std::max_element(dp, dp + size) << '\n';
    return (0);
}
