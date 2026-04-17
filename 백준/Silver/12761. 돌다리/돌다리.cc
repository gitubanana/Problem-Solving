#include <iostream>
#include <queue>

const int   MAX = 100001;

int bridge[MAX];

// +1, -1
// +-A, +-B, cur*A, cur*B

int bfs(int start, int end, int A, int B)
{
    std::queue<int> q;
    int             cur_pos, next_pos, i;
    int             offset1[] = {1, -1, A, -A, B, -B};
    int             offset2[] = {A, B};

    bridge[start] = 1;
    q.push(start);
    while (!q.empty())
    {
        cur_pos = q.front(), q.pop();
        
        for (i = 0; i < 6; ++i)
        {
            next_pos = cur_pos + offset1[i];
            if (!(0 <= next_pos && next_pos < MAX)
                || bridge[next_pos] != 0)
                continue ;
            bridge[next_pos] = bridge[cur_pos] + 1;
            if (next_pos == end)
                return (bridge[end] - 1);
            q.push(next_pos);
        }
        
        for (i = 0; i < 2; ++i)
        {
            next_pos = cur_pos * offset2[i];
            if (!(0 <= next_pos && next_pos < MAX)
                || bridge[next_pos] != 0)
                continue ;
            bridge[next_pos] = bridge[cur_pos] + 1;
            if (next_pos == end)
                return (bridge[end] - 1);
            q.push(next_pos);
        }
    }
}

int main()
{
    int A, B;
    int start, end;
    
    scanf(" %d %d %d %d", &A, &B, &start, &end);
    printf("%d\n", bfs(start, end, A, B));
    return 0;
}
