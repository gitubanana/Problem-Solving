#include <iostream>
#include <vector>
#include <algorithm>

const int   MAX = 5;

std::vector<std::string>    number;
int     map[MAX][MAX];
char    str[7];
int     size = 5;
// up, down, left, right
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};


void    dfs(int y, int x, int limit, int depth)
{
    int i;
    int next_y, next_x;

    str[depth] = map[y][x] + 1;
    if (depth == limit)
    {
        if (std::find(number.begin(), number.end(), str) == number.end())
            number.push_back(str);
        return ;
    }
    for (i = 0; i < 4; ++i)
    {
        next_y = y + dy[i];
        next_x = x + dx[i];
        if (!(0 <= next_y && next_y < size)
            || !(0 <= next_x && next_x < size))
            continue ;
        dfs(next_y, next_x, limit, depth + 1);
    }
}

int main()
{
    int y, x;
    
    for (y = 0; y < size; ++y)
        for (x = 0; x < size; ++x)
            scanf(" %d", &map[y][x]);
    for (y = 0; y < size; ++y)
        for (x = 0; x < size; ++x)
            dfs(y, x, 5, 0);
    printf("%d\n", number.size());
    return 0;
}