#include <iostream>
#include <queue>
#include <vector>

const int   MAX = 1001;

std::vector<int> map[MAX];
int cnt[MAX];

void    bfs(int start, int end)
{
    std::queue<int> q;

    q.push(start);
    cnt[start] = 1;
    while (!q.empty())
    {
        const int   &cur = q.front();
        std::vector<int>    &linked = map[cur];
        for (int i = 0; i < linked.size(); ++i)
        {
            const int   &next = linked[i];
            if (cnt[next] != 0)
                continue ;
            cnt[next] = cnt[cur] + 1;
            if (next == end)
                return ;
            q.push(next);
        }
        q.pop();
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int start, end;
    int v_cnt, e_cnt;
    int from, to;

    std::cin >> start >> end >> v_cnt >> e_cnt;
    while (e_cnt)
    {
        std::cin >> from >> to;
        map[from].push_back(to);
        map[to].push_back(from);
        --e_cnt;
    }

    bfs(start, end);

    std::cout << cnt[end] - 1 << '\n';

    return (0);
}
