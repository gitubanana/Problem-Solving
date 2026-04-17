#include <iostream>
#include <cstdio>
#include <queue>

const int   MAX = 1000001;

int map[MAX];

void    print_ans(int n)
{
    std::queue<int> q;
    int cur_pos, next_pos = 0;
    int dx[3] = {3, 2, 1};

    map[n] = 1;
    q.push(n);
    while (!q.empty())
    {
        cur_pos = q.front(), q.pop();
        for (int i = 0; i < 3; ++i)
        {
            if (cur_pos % dx[i] == 0)
            {
                next_pos = cur_pos / dx[i] - (dx[i] == 1);
                if (map[next_pos] == 0 && next_pos >= 1)
                {
                    q.push(next_pos);
                    map[next_pos] = map[cur_pos] + 1;
                }
                if (next_pos == 1)
                    break ;
            }
        }
        if (next_pos == 1)
            break ;
    }
    printf("%d\n", map[1] - 1);
}

int main(void)
{
    int n;

    scanf(" %d", &n);
    print_ans(n);
    return (0);
}
