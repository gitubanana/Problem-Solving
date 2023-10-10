#include <iostream>
#include <queue>

enum e_dice
{
    MIN_DICE = 1,
    MAX_DICE = 6
};

const int   MAX = 100;

int teleport[MAX + 1];
int cnt[MAX + 1];

void    bfs(const int start, const int end)
{
    std::queue<int> q;

    cnt[start] = 1;
    q.push(start);
    while (!q.empty())
    {
        const int   &cur = q.front();
        for (int i = MIN_DICE; i <= MAX_DICE; ++i)
        {
            int   next = teleport[cur + i];
            if (!(next <= MAX)
                || cnt[next] != 0)
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

    int       from, to;
    int       ladder_cnt, snake_cnt;
    const int start = 1, end = 100;

    for (int i = start; i <= end; ++i)
        teleport[i] = i;

    std::cin >> ladder_cnt >> snake_cnt;
    ladder_cnt += snake_cnt;
    while (ladder_cnt--)
        std::cin >> from >> to, teleport[from] = to;

    bfs(start, end);
    std::cout << cnt[end] - 1 << '\n';
    return (0);
}
