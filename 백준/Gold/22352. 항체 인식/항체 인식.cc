#include <iostream>

enum e_idx
{
    BEFORE,
    AFTER,
    Z_SIZE
};

const int   MAX = 30;

int map[Z_SIZE][MAX][MAX];
int visited[MAX][MAX];
int y_size, x_size, fill, save;
// 위, 아래, 오른쪽, 왼쪽
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};

void    dfs(int y, int x)
{
    int i;
    int next_y, next_x;

    visited[y][x] = 1;
    map[BEFORE][y][x] = fill;
    for (i = 0; i < 4; ++i)
    {
        next_y = y + dy[i];
        next_x = x + dx[i];
        if (!(0 <= next_y && next_y < y_size)
            || !(0 <= next_x && next_x < x_size)
            || visited[next_y][next_x]
            || save != map[BEFORE][next_y][next_x])
            continue ;
        dfs(next_y, next_x);
    }
}

void    check_ans(void)
{
    int y, x;
    
    for (y = 0; y < y_size; ++y)
        for (x = 0; x < x_size; ++x)
            if (map[BEFORE][y][x] != map[AFTER][y][x])
                printf("NO\n"), exit(0);
    printf("YES\n"), exit(0);
}

int main()
{
    int z, y, x;
    
    scanf(" %d %d", &y_size, &x_size);
    for (z = 0; z < Z_SIZE; ++z)
        for (y = 0; y < y_size; ++y)
            for (x = 0; x < x_size; ++x)
                scanf(" %d", &map[z][y][x]);
    for (y = 0; y < y_size; ++y)
        for (x = 0; x < x_size; ++x)
            if (map[BEFORE][y][x] != map[AFTER][y][x])
                fill = map[AFTER][y][x], save = map[BEFORE][y][x], dfs(y, x), check_ans();
    printf("YES\n");
    return 0;
}