#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>

using t_uset = std::unordered_set<std::string>;

int reverseCnt;
t_uset visited;
std::queue<std::string> q;

inline bool isAscending(const std::string &str)
{
    int size = str.size();

    for (int cur = 1; cur < size; ++cur)
    {
        if (str[cur - 1] > str[cur])
        {
            return (false);
        }
    }
    return (true);
}

int bfs(const std::string &start)
{
    if (isAscending(start))
        return (0);

    int changeCnt = 0;

    visited.insert(start);
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();

        ++changeCnt;
        while (qSize--)
        {
            const std::string cur = q.front();
            q.pop();

            for (int r = cur.size() - reverseCnt; r >= 0; --r)
            {
                std::string next = cur;
                std::reverse(
                    next.begin() + r,
                    next.begin() + r + reverseCnt
                );

                if (visited.find(next) != visited.end())
                    continue ;

                if (isAscending(next))
                    return (changeCnt);

                visited.insert(next);
                q.push(next);
            }
        }
    }

    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    std::string start;

    std::cin >> size >> reverseCnt;
    while (size--)
    {
        char ch;

        std::cin >> ch;
        start.push_back(ch);
    }

    std::cout << bfs(start) << '\n';
    return (0);
}
