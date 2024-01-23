#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

enum e_space
{
    CHEESE = '1',
    EMPTY = '0'
};

struct t_pos
{
    int y, x;
};

const int MAX = 100;

int cheeseCnt;
int ySize, xSize;
bool visited[MAX][MAX];
char map[MAX][MAX + 1];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void    bfs(const t_pos &start)
{
    std::queue<t_pos> q;

    visited[start.y][start.x] = true;
    q.push(start);
    while (!q.empty())
    {
        t_pos &cur = q.front();
        for (int i = 0; i < 4; ++i)
        {
            t_pos next = {cur.y + dy[i], cur.x + dx[i]};

            if (!(0 <= next.y && next.y < ySize)
                || !(0 <= next.x && next.x < xSize)
                || visited[next.y][next.x])
                continue ;

            visited[next.y][next.x] = true;
            char &nextSpace = map[next.y][next.x];
            switch (nextSpace)
            {
            case CHEESE:
                map[next.y][next.x] = EMPTY;
                --cheeseCnt;
                break;
            default:
                q.push(next);
                break;
            }
        }
        q.pop();
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
            cheeseCnt += (map[y][x] == CHEESE);
        }
    }

    int time_ = 1;
    int prevCheeseCnt = cheeseCnt;
    while (true)
    {
        bfs({0, 0});
        if (cheeseCnt == 0)
            break ;
        prevCheeseCnt = cheeseCnt;
        memset(visited, false, sizeof(visited));
        ++time_;
    }

    std::cout << time_ << '\n';
    std::cout << prevCheeseCnt << '\n';
    return (0);
}