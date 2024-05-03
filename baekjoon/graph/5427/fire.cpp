#include <iostream>
#include <queue>

struct t_pos
{
    int y, x;
};

enum e_space
{
    WALL = '#',
    EMPTY = '.',
    ME = '@',
    FIRE = '*'
};

typedef std::queue<t_pos> t_queue;

const int MAX = 1000;
const int IMPOSSIBLE = -1;

char map[MAX][MAX + 1];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int ySize, xSize, time_ = 1;

void    simulation(t_queue &meQ, t_queue &fireQ)
{
    while (true)
    {
        int meQsize = meQ.size();
        while (meQsize--)
        {
            t_pos &cur = meQ.front();

            if (map[cur.y][cur.x] == ME)
            {
                map[cur.y][cur.x] = WALL;
                for (int i = 0; i < 4; ++i)
                {
                    t_pos next = {cur.y + dy[i], cur.x + dx[i]};

                    if (next.y == -1 || next.y == ySize
                        || next.x == -1 || next.x == xSize)
                        return ;

                    char &nextSpace = map[next.y][next.x];
                    if (nextSpace == EMPTY)
                    {
                        nextSpace = ME;
                        meQ.push(next);
                    }
                }
            }
            meQ.pop();
        }

        int meCnt = meQ.size();
        int fireCnt = fireQ.size();
        while (fireCnt--)
        {
            t_pos &cur = fireQ.front();

            for (int i = 0; i < 4; ++i)
            {
                t_pos next = {cur.y + dy[i], cur.x + dx[i]};

                if (next.y == -1 || next.y == ySize
                    || next.x == -1 || next.x == xSize)
                    continue ;

                char &nextSpace = map[next.y][next.x];
                if (nextSpace != WALL
                    && nextSpace != FIRE)
                {
                    meCnt -= (nextSpace == ME);
                    nextSpace = FIRE;
                    fireQ.push(next);
                }
            }
            fireQ.pop();
        }

        if (meCnt == 0)
        {
            time_ = IMPOSSIBLE;
            break ;
        }
        ++time_;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        t_queue meQ, fireQ;

        std::cin >> xSize >> ySize;
        for (int y = 0; y < ySize; ++y)
        {
            std::cin >> map[y];
            for (int x = 0; x < xSize; ++x)
            {
                switch (map[y][x])
                {
                case ME:
                    meQ.push({y, x});
                    break;
                case FIRE:
                    fireQ.push({y, x});
                    break;
                }
            }
        }

        time_ = 1;
        simulation(meQ, fireQ);

        if (time_ == IMPOSSIBLE)
            std::cout << "IMPOSSIBLE";
        else
            std::cout << time_;
        std::cout << '\n';
    }

    return (0);
}