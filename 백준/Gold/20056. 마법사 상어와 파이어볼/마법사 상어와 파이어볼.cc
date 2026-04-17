#include <iostream>
#include <vector>
#define CURMAP map[curIdx]
#define NEXTMAP map[nextIdx]

struct t_atom
{
    int mass;
    int speed;
    int dir;
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 50;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size;
int curIdx, nextIdx;
std::vector<t_pos> toCompose;
std::vector<t_atom> map[2][MAX_SIZE][MAX_SIZE];

int getTotalMass(void)
{
    int totalMass = 0;

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            for (const t_atom &atom : CURMAP[y][x])
            {
                totalMass += atom.mass;
            }
        }
    }
    return (totalMass);
}

void    moveAll(void)
{
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::vector<t_atom> &curSpace = CURMAP[y][x];

            for (t_atom &atom : curSpace)
            {
                t_pos next = {
                    (y + dy[atom.dir] * (atom.speed % size) + size) % size,
                    (x + dx[atom.dir] * (atom.speed % size) + size) % size
                };
                std::vector<t_atom> &nextSpace = NEXTMAP[next.y][next.x];

                nextSpace.push_back(atom);
                if (nextSpace.size() == 2)
                {
                    toCompose.push_back(next);
                }
            }

            curSpace.clear();
        }
    }
}

void    composeAll(void)
{
    for (const t_pos &pos : toCompose)
    {
        int massSum = 0;
        int speedSum = 0;
        bool isOdd = false;
        bool isEven = false;
        std::vector<t_atom> &nextSpace = NEXTMAP[pos.y][pos.x];

        for (t_atom &atom : nextSpace)
        {
            bool odd = (atom.dir & 1);

            isOdd |= odd;
            isEven |= !odd;
            massSum += atom.mass;
            speedSum += atom.speed;
        }

        massSum /= 5;
        speedSum /= nextSpace.size();
        nextSpace.clear();

        if (massSum == 0)
            continue ;

        for (int dir = !(isOdd ^ isEven); dir < dirSize; dir += 2)
        {
            nextSpace.push_back({massSum, speedSum, dir});
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt, move;

    std::cin >> size >> vCnt >> move;
    while (vCnt--)
    {
        int y, x, mass, speed, dir;
    
        std::cin >> y >> x >> mass >> speed >> dir;
        CURMAP[y - 1][x - 1].push_back({mass, speed, dir});
    }

    while (move--)
    {
        nextIdx = curIdx ^ 1;
        toCompose.clear();
        moveAll();
        composeAll();
        curIdx = nextIdx;
    }

    std::cout << getTotalMass() << '\n';
    return 0;
}
