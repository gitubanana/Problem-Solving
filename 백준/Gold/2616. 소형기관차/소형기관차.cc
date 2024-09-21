#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

const int MAX_SIZE = 50'000;
const int DEPTH_LIMIT = 3;

int maxTake;
int arrSize;
int windowSize;
int takeSize;
int arr[MAX_SIZE];
int take[MAX_SIZE];
int dp[MAX_SIZE][DEPTH_LIMIT];

int dfs(int cur=0, int depth=0)
{
    if (cur > takeSize || depth == DEPTH_LIMIT)
    {
        return (0);
    }

    int &curDp = dp[cur][depth];
    if (curDp != 0)
    {
        return (curDp);
    }

    curDp = std::max(
        take[cur] + dfs(cur + windowSize, depth + 1),
        dfs(cur + 1, depth)
    );

    return (curDp);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> arrSize;
    for (int i = 0; i < arrSize; ++i)
    {
        std::cin >> arr[i];
    }
    std::cin >> windowSize;

    for (int i = 0; i < windowSize; ++i)
    {
        take[takeSize] += arr[i];
    }

    for (int i = windowSize; i < arrSize; ++i)
    {
        ++takeSize;
        take[takeSize] = take[takeSize - 1] + arr[i] - arr[i - windowSize];
    }

    std::cout << dfs() << '\n';
    return (0);
}
