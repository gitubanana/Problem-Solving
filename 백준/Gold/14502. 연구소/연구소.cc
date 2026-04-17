#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

enum e_space
{
    EMPTY,
    WALL,
    VIRUS
};

struct t_pos
{
    int y;
    int x;
};

const int MAX = 8;
int map[MAX][MAX];
int visited[MAX][MAX];

int max;
int y_size, x_size;
// up, down, left, right
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void    bfs(std::vector<t_pos> &virus_pos)
{
    int                 i;
    std::queue<t_pos>   q;
    t_pos               cur_pos, next_pos;

    for (i = 0; i < virus_pos.size(); ++i)
        q.push(virus_pos[i]);

    while (!q.empty())
    {
        cur_pos = q.front(), q.pop();
        for (i = 0; i < 4; ++i)
        {
            next_pos.y = cur_pos.y + dy[i];
            next_pos.x = cur_pos.x + dx[i];
            if (!(0 <= next_pos.y && next_pos.y < y_size)
                || !(0 <= next_pos.x && next_pos.x < x_size)
                || map[next_pos.y][next_pos.x] != EMPTY
                || visited[next_pos.y][next_pos.x] == 1)
                continue ;
            visited[next_pos.y][next_pos.x] = 1;
            q.push(next_pos);
        }
    }
}

void    count_safe_place(void)
{
    int y, x;
    int cnt = 0;

    for (y = 0; y < y_size; ++y)
        for (x = 0; x < x_size; ++x)
            if (map[y][x] == EMPTY && visited[y][x] == 0)
                ++cnt;
    max = std::max(max, cnt);
}

int main()
{
    t_pos   cur_pos;
    std::vector<t_pos>  virus_pos;
    std::vector<t_pos>  empty_pos;

    scanf(" %d %d", &y_size, &x_size);
    for (int y = 0; y < y_size; ++y)
    {
        for (int x = 0; x < x_size; ++x)
        {
            scanf(" %d", &map[y][x]);
            if (map[y][x] == VIRUS)
                virus_pos.push_back({y, x});
            else if (map[y][x] == EMPTY)
                empty_pos.push_back({y, x});
        }
    }

    int one, two, three;
    for (one = 0; one < empty_pos.size() - 2; ++one)
    {
        for (two = one + 1; two < empty_pos.size() - 1; ++two)
        {
            for (three = two + 1; three < empty_pos.size(); ++three)
            {
                map[empty_pos[one].y][empty_pos[one].x] = WALL;
                map[empty_pos[two].y][empty_pos[two].x] = WALL;
                map[empty_pos[three].y][empty_pos[three].x] = WALL;

                bfs(virus_pos);
                count_safe_place();

                memset(visited, 0, sizeof(visited));
                map[empty_pos[one].y][empty_pos[one].x] = EMPTY;
                map[empty_pos[two].y][empty_pos[two].x] = EMPTY;
                map[empty_pos[three].y][empty_pos[three].x] = EMPTY;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}