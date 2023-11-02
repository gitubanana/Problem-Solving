#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

const int   MAX = 1e9 + 1;

typedef long long num_t;

void    bfs(num_t start, num_t end)
{
    std::queue<num_t> q;
    num_t             next[2];
    num_t             q_size, cnt = 1;

    q.push(start);
    while (!q.empty())
    {
        q_size = q.size();
        while (q_size--)
        {
            const num_t &cur = q.front();
            next[0] = cur * 2;
            next[1] = cur * 10 + 1;
            for (num_t i = 0; i < 2; ++i)
            {
                if (next[i] > end)
                    continue ;
                if (next[i] == end)
                {
                    std::cout << cnt + 1 << '\n';
                    return ;
                }
                q.push(next[i]);
            }
            q.pop();
        }
        ++cnt;
    }
    std::cout << "-1\n";
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int start, end;

    std::cin >> start >> end;

    bfs(start, end);
    return 0;
}
