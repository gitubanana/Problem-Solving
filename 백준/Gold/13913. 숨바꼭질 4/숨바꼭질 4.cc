#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

const int   MAX = 100000;
const int   START = -1;

int prev_num[MAX + 1];

int dx[] = {-1, 1, 0};

void    bfs(int start, int dest)
{
    int i;
    int cur_pos, next_pos;
    std::queue<int> q;

    q.push(start);
    while (!q.empty())
    {
        cur_pos = q.front(), q.pop();
        dx[2] = cur_pos;
        for (i = 0; i < 3; ++i)
        {
            next_pos = cur_pos + dx[i];
            if (!(0 <= next_pos && next_pos <= MAX)
                || prev_num[next_pos])
                continue ;
            prev_num[next_pos] = cur_pos + 1;
            if (next_pos == dest)
                return ;
            q.push(next_pos);
        }
    }
}

int main(void)
{
    int start, dest;

    scanf(" %d %d", &start, &dest);

    prev_num[start] = START;
    if (start != dest)
        bfs(start, dest);

    int cur;
    std::vector<int>    ans;

    cur = dest;
    while (prev_num[cur] != START)
    {
        ans.push_back(cur);
        cur = prev_num[cur] - 1;
    }
    printf("%d\n", ans.size());
    printf("%d ", start);
    for (int i = ans.size() - 1; i >= 0; --i)
        printf("%d ", ans[i]);
    printf("\n");
    return (0);
}