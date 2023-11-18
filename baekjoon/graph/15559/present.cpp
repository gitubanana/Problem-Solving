#include <iostream>

const int   MAX = 1000;

char map[MAX][MAX + 1];
int  visited[MAX][MAX];
int  y_size, x_size, cnt, id;
int  dy[] = {-1, 1, 0, 0};
int  dx[] = {0, 0, -1, 1};

void    dfs(int y, int x)
{
    static const std::string &move_ch = "NSWE";

    int idx = move_ch.find(map[y][x]);
    int next_y = y + dy[idx];
    int next_x = x + dx[idx];
    int &next_visited = visited[next_y][next_x];

    visited[y][x] = id;
    if (next_visited == 0)
        dfs(next_y, next_x);
    else if (next_visited == id)
        ++cnt;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> y_size >> x_size;
    for (int y = 0; y < y_size; ++y)
        std::cin >> map[y];

    for (int y = 0; y < y_size; ++y)
    {
        for (int x = 0; x < x_size; ++x)
        {
            if (visited[y][x] == 0)
            {
                ++id;
                dfs(y, x);
            }
        }
    }
    std::cout << cnt << '\n';
    return (0);
}
