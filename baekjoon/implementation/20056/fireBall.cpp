#include <iostream>
#include <vector>
#define CURMAP map[mapIdx]
#define NEXTMAP map[nextMapIdx]

struct t_fire
{
    int dir;
    int speed;
    int mass;
};

const int MAX = 51;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size, mapIdx, nextMapIdx;
std::vector<t_fire> map[2][MAX][MAX];

inline std::istream &operator>>(std::istream &in, t_fire &input)
{
    in >> input.mass >> input.speed >> input.dir;
    return (in);
}

int getFinalMass(void)
{
    int fianlMass = 0;

    for (int y = 1; y <= size; ++y)
    {
        for (int x = 1; x <= size; ++x)
        {
            for (const t_fire &fire : map[mapIdx][y][x])
            {
                fianlMass += fire.mass;
            }
        }
    }
    return (fianlMass);
}

inline void linkCoordinate(int &pos)
{
    if (pos == size + 1)
        pos = 1;
    else if (pos == 0)
        pos = size;
}

void    moveFireBalls(void)
{
    for (int y = 1; y <= size; ++y)
    {
        for (int x = 1; x <= size; ++x)
        {
            for (const t_fire &fire : CURMAP[y][x])
            {
                int nextY = y;
                int nextX = x;

                for (int i = 0; i < fire.speed; ++i)
                {
                    nextY += dy[fire.dir];
                    nextX += dx[fire.dir];

                    linkCoordinate(nextY);
                    linkCoordinate(nextX);
                }

                NEXTMAP[nextY][nextX].push_back(fire);
            }

            CURMAP[y][x].clear();
        }
    }
}

int sumMass(std::vector<t_fire> &fires)
{
    int mass = 0;

    for (const t_fire &fire : fires)
    {
        mass += fire.mass;
    }
    return (mass);
}

int sumSpeed(std::vector<t_fire> &fires)
{
    int speed = 0;

    for (const t_fire &fire : fires)
    {
        speed += fire.speed;
    }
    return (speed);
}

bool isAllEvenOdd(std::vector<t_fire> &fires)
{
    bool isOdd = fires[0].dir & 1;

    for (int i = 1; i < fires.size(); ++i)
    {
        if (isOdd != (fires[i].dir & 1))
        {
            return (false);
        }
    }
    return (true);
}

void    combineFireBalls(void)
{
    for (int y = 1; y <= size; ++y)
    {
        for (int x = 1; x <= size; ++x)
        {
            if (NEXTMAP[y][x].size() < 2)
                continue ;

            const int fireCnt = NEXTMAP[y][x].size();
            const int newMass = sumMass(NEXTMAP[y][x]) / 5;
            const int newSpeed = sumSpeed(NEXTMAP[y][x]) / fireCnt;
            int newDir = !isAllEvenOdd(NEXTMAP[y][x]);

            NEXTMAP[y][x].clear();
            if (newMass == 0)
                continue ;

            for (; newDir < dirSize; newDir += 2)
            {
                NEXTMAP[y][x].push_back({newDir, newSpeed, newMass});
            }
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int y, x;
    t_fire fire;
    int fireCnt, cmdCnt;

    std::cin >> size >> fireCnt >> cmdCnt;
    while (fireCnt--)
    {
        std::cin >> y >> x >> fire;
        CURMAP[y][x].push_back(fire);
    }
    while (cmdCnt--)
    {
        nextMapIdx = (mapIdx + 1) % 2;
        moveFireBalls();
        combineFireBalls();
        mapIdx = nextMapIdx;
    }

    std::cout << getFinalMass() << '\n';
    return (0);
}
