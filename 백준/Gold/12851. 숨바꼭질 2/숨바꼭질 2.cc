#include <iostream>
#include <cstdio>
#include <queue>

const int   MAX = 100000;

int map[MAX + 1];
int cnt = 1;
int dx[] = {-1, 1, 0};

void    bfs(int start, int dest)
{
    std::queue<int> q;
    int i, cur_pos, next_pos;
    int next_value;

    map[start] = 0;
    q.push(start);
    while (!q.empty())
    {
        cur_pos = q.front(), q.pop();
        dx[2] = cur_pos;
        for (i = 0; i < 3; ++i)
        {
            next_pos = cur_pos + dx[i];
            if (!(0 <= next_pos && next_pos <= MAX))
                continue ;
            next_value = map[cur_pos] + 1;
            if (map[dest] == 0)
            {
                if (!(map[next_pos] == 0 || map[next_pos] == next_value))
                    continue ;

                map[next_pos] = next_value;
                if (next_pos != dest)
                    q.push(next_pos);
            }
            else
            {
                if (next_pos == dest)
                {
                    if (next_value == map[dest])
                        ++cnt;
                }
                else if (next_value < map[dest])
                {
                    q.push(next_pos);
                }
            }
        }
    }
}

int main(void)
{
    int start, dest;

    scanf(" %d %d", &start, &dest);
    if (start == dest)
        cnt = 1;
    else
        bfs(start, dest);
    printf("%d\n%d\n", map[dest], cnt);
    return (0);
}