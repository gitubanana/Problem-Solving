#include <iostream>
#include <queue>

enum e_space
{
    EMPTY = '.',
    WATER = '*',
    WALL = 'X',
    START = 'S',
    END = 'D'
};

struct t_pos
{
    int y, x;
};

const int FAIL = -1;
const int MAX_SIZE = 50;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];
std::queue<t_pos> beaverQ;
std::queue<t_pos> waterQ;

int saveBeaver(void)
{
    int curTime = 1;

    while (!beaverQ.empty())
    {
        int wQsize = waterQ.size();
        while (wQsize--)
        {
            const t_pos cur = waterQ.front();
            waterQ.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                const t_pos next = {cur.y + dy[dir], cur.x + dx[dir]};

                if (!(0 <= next.y && next.y < ySize)
                    || !(0 <= next.x && next.x < xSize)
                    || map[next.y][next.x] == WALL)
                    continue ;

                char &nextSpace = map[next.y][next.x];
                if (nextSpace == END)
                    continue ;

                nextSpace = WALL;
                waterQ.push(next);
            }
        }

        int bQsize = beaverQ.size();
        while (bQsize--)
        {
            const t_pos cur = beaverQ.front();
            beaverQ.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                const t_pos next = {cur.y + dy[dir], cur.x + dx[dir]};

                if (!(0 <= next.y && next.y < ySize)
                    || !(0 <= next.x && next.x < xSize)
                    || map[next.y][next.x] == WALL)
                    continue ;

                char &nextSpace = map[next.y][next.x];
                if (nextSpace == END)
                    return (curTime);

                nextSpace = WALL;
                beaverQ.push(next);
            }
        }

        ++curTime;
    }
    return (FAIL);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
        for (int x = 0; x < xSize; ++x)
        {
            char &curSpace = map[y][x];

            switch (curSpace)
            {
            case START:
                beaverQ.push({y, x});
                map[y][x] = WALL;
                break;
            case WATER:
                waterQ.push({y, x});
                map[y][x] = WALL;
                break;
            }
        }
    }

    int timeToGo = saveBeaver();
    if (timeToGo == FAIL)
    {
        std::cout << "KAKTUS" << '\n';
    }
    else
    {
        std::cout << timeToGo << '\n';
    }
    return (0);
}
