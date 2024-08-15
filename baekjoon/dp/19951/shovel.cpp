#include <iostream>

const int MAX_SIZE = 100001;

int size;
int arr[MAX_SIZE], dp[MAX_SIZE];

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int cmdCnt;

    std::cin >> size >> cmdCnt;
    for (int i = 1; i <= size; ++i)
    {
        std::cin >> arr[i];
    }

    while (cmdCnt--)
    {
        int from, to, delta;

        std::cin >> from >> to >> delta;
        dp[from - 1] += delta;
        dp[to] += -delta;
    }

    for (int i = 1; i <= size; ++i)
    {
        dp[i] += dp[i - 1];
        std::cout << arr[i] + dp[i - 1] << ' ';
    }
    std::cout << '\n';

    return 0;
}
