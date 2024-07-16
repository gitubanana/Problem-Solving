#include <iostream>
#include <unordered_set>

// ** 아무 생각 없는 dfs **
// 최대 6C2번을 고를 수 있다. => 10^15이 되므로 시간초과!!!
// visited로 저장을 Cutting

using t_uset = std::unordered_set<std::string>;

std::string result;
t_uset visited[11];

void    dfs(std::string &num, int swapCnt)
{
    if (swapCnt == 0)
    {
        result = std::max(result, num);
        return ;
    }

    visited[swapCnt].insert(num);
    for (int y = 0; y < num.size() - 1; ++y)
    {
        for (int x = y + 1; x < num.size(); ++x)
        {
            std::swap(num[y], num[x]);

            t_uset &nextVisited = visited[swapCnt - 1];
            if (nextVisited.find(num) == visited[swapCnt - 1].end())
            {
                dfs(num, swapCnt - 1);
            }

            std::swap(num[y], num[x]);
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        int swapCnt;
        std::string num;
        std::cin >> num >> swapCnt;

        result = "";
        for (int i = 1; i <= swapCnt; ++i)
        {
            visited[i].clear();
        }
        dfs(num, swapCnt);
        std::cout << '#' << t << ' ' << result << '\n';
    }
    return (0);
}
