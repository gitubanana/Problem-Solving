#include <iostream>
#include <cstring>
#include <queue>

struct t_atom
{
    int y, x;
    int dir;
    int energy;
};

struct t_space
{
    int atomIdx;
    int cameTime;
};

const int DELETED = 0;
const int TO_IDX = 1000;
const int MAX_SIZE = TO_IDX * 2 + 1;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, -1, 1};

std::queue<int> q;
t_atom atoms[TO_IDX + 1];
t_space map[MAX_SIZE][MAX_SIZE];

int simulation(void)
{
    int curTime = 2;
    int outEnergy = 0;

    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            int curIdx = q.front();
            t_atom &cur = atoms[curIdx];
            q.pop();

            if (cur.energy == DELETED)
                continue ;

            cur.y += dy[cur.dir];
            cur.x += dx[cur.dir];
            if (!(0 <= cur.y && cur.y < MAX_SIZE)
                || !(0 <= cur.x && cur.x < MAX_SIZE))
                continue ;

            t_space &curSpace = map[cur.y][cur.x];
            t_atom &bumpInto = atoms[curSpace.atomIdx];

            if (curSpace.cameTime == curTime
                || (curSpace.cameTime == curTime - 1
                    && cur.dir == (bumpInto.dir ^ 1)))
            {
                outEnergy += cur.energy + bumpInto.energy;
                cur.energy = bumpInto.energy = DELETED;
                cur.dir = bumpInto.dir = -1;
                continue ;
            }

            curSpace.atomIdx = curIdx;
            curSpace.cameTime = curTime;
            q.push(curIdx);
        }

        ++curTime;
    }

    return (outEnergy);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        int atomCnt;

        memset(map, 0, sizeof(map));
        std::cin >> atomCnt;
        for (int id = 1; id <= atomCnt; ++id)
        {
            t_atom &cur = atoms[id];

            std::cin >> cur.x >> cur.y >> cur.dir >> cur.energy;
            cur.y += TO_IDX;
            cur.x += TO_IDX;
            map[cur.y][cur.x].atomIdx = id;
            map[cur.y][cur.x].cameTime = 1;
            q.push(id);
        }

        std::cout << '#' << t << ' ' << simulation() << '\n';        
    }

    return (0);
}
