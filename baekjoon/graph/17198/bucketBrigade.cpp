#include <iostream>
#include <queue>

enum e_space
{
    START = 'L',
    END = 'B',
    WALL = 'R',
    EMPTY = '.'
};

struct t_pos
{
    int y, x;
};

const int SIZE = 10;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

char map[SIZE][SIZE + 1];

int bfs(const t_pos &start)
{
    int cowCnt = 0;
    std::queue<t_pos> q;

    map[start.y][start.x] = WALL;
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            const t_pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {
                    cur.y + dy[dir],
                    cur.x + dx[dir]
                };

                if (!(0 <= next.y && next.y < SIZE)
                    || !(0 <= next.x && next.x < SIZE)
                    || map[next.y][next.x] == WALL)
                    continue ;

                char &nextSpace = map[next.y][next.x];
                if (nextSpace == END)
                    return (cowCnt);

                nextSpace = WALL;
                q.push(next);
            }
        }
        ++cowCnt;
    }
    return (cowCnt);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos start = {-1, -1};

    for (int y = 0; y < SIZE; ++y)
    {
        std::cin >> map[y];
        if(start.y != -1)
            continue ;

        for (int x = 0; x < SIZE; ++x)
        {
            if (map[y][x] == START)
            {
                start.y = y, start.x = x;
                break ;
            }
        }
    }

    std::cout << bfs(start) << '\n';
    return (0);
}
