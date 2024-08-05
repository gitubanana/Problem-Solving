#include <iostream>
#include <cstring>

const int MAX_SIZE = 100;
const int MIN_NUM = 0;
const int MAX_NUM = 20;

int size;
int num[MAX_SIZE];
int64_t dp[MAX_SIZE - 1][MAX_NUM + 1];

int64_t dfs(int cur, int depth=1)
{
    static const int depthLimit = size - 1;

    if (depth == depthLimit)
    {
        return (cur == num[depthLimit]);
    }

    int64_t &curDp = dp[depth][cur];
    if (curDp != -1)
    {
        return (curDp);
    }

    curDp = 0;

    int plus = cur + num[depth];
    if (plus <= MAX_NUM)
    {
        curDp += dfs(plus, depth + 1);
    }

    int minus = cur - num[depth];
    if (minus >= MIN_NUM)
    {
        curDp += dfs(minus, depth + 1);
    }

    return (curDp);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> num[i];
    }

    memset(dp, -1, sizeof(dp));
    std::cout << dfs(num[0]) << '\n';
    return (0);
}
