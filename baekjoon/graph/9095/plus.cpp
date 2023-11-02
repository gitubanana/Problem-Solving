#include <iostream>
#include <queue>
#include <cstring>

const int   MAX = 10;

int ans;
int dx[] = {1, 2, 3};
int dx_size = sizeof(dx) / sizeof(dx[0]);

void    bfs(int start, int end)
{
    int i;
    std::queue<int> q;

    q.push(start);
    while (!q.empty())
    {
        const int   &cur_v = q.front();
        for (i = 0; i < dx_size; ++i)
        {
            int next_v = cur_v + dx[i];

            if (next_v == end)
                ++ans;
            else if (next_v < end)
                q.push(next_v);
        }
        q.pop();
    }
}

int main(void)
{
    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int test_cnt, end;

    std::cin >> test_cnt;
    while (test_cnt)
    {
        std::cin >> end;

        bfs(0, end);
        std::cout << ans << '\n';
        ans = 0;
        --test_cnt;
    }
    return (0);
}
