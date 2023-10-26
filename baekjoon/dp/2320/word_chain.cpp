#include <iostream>
#include <algorithm>

const int   MAX = 16;

int size, max;
int dp[MAX];
int visited[MAX];
std::string arr[MAX];

void find_value(int cur_idx, std::string &cur)
{
    int     cur_size = dp[cur_idx];
    char    &cur_back = cur.back();

    visited[cur_idx] |= (1 << cur_idx);
    for (int i = 0; i < size; ++i)
    {
        std::string &cmp = arr[i];
        if (cmp[0] != cur_back
            || visited[cur_idx] & (1 << i))
            continue ;

        int total_size = cur_size + cmp.size();

        if (dp[i] <= total_size)
        {
            dp[i] = total_size;
            visited[i] = visited[cur_idx] | (1 << cur_idx);
            find_value(i, arr[i]);
        }

        if (max < dp[i])
            max = dp[i];
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int i = 0; i < size; ++i)
        std::cin >> arr[i];

    std::sort(arr, arr + size);

    for (int i = 0; i < size; ++i)
    {
        std::string &cur = arr[i];
        int         cur_size = cur.size();

        dp[i] = std::max(dp[i], cur_size);
        if (max < dp[i])
            max = dp[i];
        find_value(i, cur);
    }

    std::cout << max << '\n';
    return (0);
}
