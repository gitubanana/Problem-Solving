#include <iostream>
#include <queue>

const int   Y_MAX = 100;
const int   X_MAX = 70;

int map[Y_MAX][X_MAX];
int visited[Y_MAX][X_MAX];
// 위, 아래, 오른쪽, 왼쪽, 위 + 오른쪽, 위 + 왼쪽, 아래 + 오른쪽, 아래 + 왼쪽
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool    dfs(int y, int x, int y_size, int x_size)
{
    int     i;
    int     next_y, next_x;
    bool    ret = true;

    visited[y][x] = 1;
    for (i = 0; i < 8; ++i)
    {
        next_y = y + dy[i];
        next_x = x + dx[i];
        if (!(0 <= next_y && next_y < y_size)
            || !(0 <= next_x && next_x < x_size))
            continue ;
        if (map[y][x] < map[next_y][next_x])
            ret = false;
        else if (!visited[next_y][next_x] && map[y][x] == map[next_y][next_x])
            ret *= dfs(next_y, next_x, y_size, x_size);
    }
    return (ret);
}

int main(void)
{
    int y, x;
    int y_size, x_size;
    int cnt = 0;

    scanf(" %d %d", &y_size, &x_size);
    for (y = 0; y < y_size; ++y)
        for (x = 0; x < x_size; ++x)
            scanf(" %d", &map[y][x]);
    for (y = 0; y < y_size; ++y)
        for (x = 0; x < x_size; ++x)
            if (visited[y][x] == 0 && dfs(y, x, y_size, x_size))
                ++cnt;
    printf("%d\n", cnt);
    return 0;
}
