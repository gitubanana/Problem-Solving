#include <iostream>
#include <cstdio>
#include <queue>

typedef struct
{
        int     y;
        int     x;
}       t_pos;

const int       MAX = 1000;

int     map[MAX][MAX];
int     visited[MAX][MAX];
//위, 아래, 오른쪽, 왼쪽
int     dy[] = {-1, 1, 0, 0};
int     dx[] = {0, 0, 1, -1};

void    bfs(t_pos &start, int &y_size, int &x_size)
{
        int                                     i;
        std::queue<t_pos>       q;
        t_pos                           cur_pos, next_pos;

        map[start.y][start.x] = 0;
        visited[start.y][start.x] = 1;
        q.push(start);
        while (!q.empty())
        {
                cur_pos = q.front(), q.pop();
                for (i = 0; i < 4; i++)
                {
                        next_pos.y = cur_pos.y + dy[i];
                        next_pos.x = cur_pos.x + dx[i];
                        if (!(0 <= next_pos.y && next_pos.y < y_size)
                                || !(0 <= next_pos.x && next_pos.x < x_size)
                                || map[next_pos.y][next_pos.x] != 1
                                || visited[next_pos.y][next_pos.x] == 1)
                                continue ;
                        q.push(next_pos);
                        visited[next_pos.y][next_pos.x] = 1;
                        map[next_pos.y][next_pos.x] = map[cur_pos.y][cur_pos.x] + 1;
                }
        }
}

int     main(void)
{
        int             y, x;
        int             y_size, x_size;
        t_pos   start;

        std::cin >> y_size >> x_size;
        for (y = 0; y < y_size; y++)
        {
                for (x = 0; x < x_size; x++)
                {
                        std::cin >> map[y][x];
                        if (map[y][x] == 2)
                                start.y = y, start.x = x;
                }
        }
        bfs(start, y_size, x_size);
        for (y = 0; y < y_size; y++)
        {
                for (x = 0; x < x_size; x++)
                        std::cout << ((map[y][x] == 1 && visited[y][x] == 0) ? -1 : map[y][x]) << " ";
                std::cout << std::endl;
        }
        return (0);
}