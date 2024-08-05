#include <iostream>
#include <vector>

enum e_idx
{
    Y = 0,
    X
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 300;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize, rotateCnt;
int map[MAX_SIZE][MAX_SIZE];
int nextMap[MAX_SIZE][MAX_SIZE];
std::vector<t_pos> rotatePos;

void    makeRotatePos(int pos, int lens[2])
{
    rotatePos.clear();

    int lenIdx = 0;
    int y = pos, x = pos;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int len = lens[lenIdx];
        while (--len)
        {
            rotatePos.push_back({y, x});
            y += dy[dir];
            x += dx[dir];
        }

        lenIdx ^= 1;
    }
}

void    putNextMap(int R)
{
    for (int i = 0; i < rotatePos.size(); ++i)
    {
        t_pos &cur = rotatePos[i];
        t_pos &next = rotatePos[(i + R) % rotatePos.size()];

        nextMap[next.y][next.x] = map[cur.y][cur.x];
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize >> rotateCnt;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    int pos = 0;
    int lens[] = {ySize, xSize};
    do
    {
        int period = (lens[Y] - 1) * 2 + (lens[X] - 1) * 2;

        makeRotatePos(pos, lens);
        putNextMap(rotateCnt % period);

        ++pos;
        lens[Y] -= 2;
        lens[X] -= 2;
    } while (lens[Y] > 0 && lens[X] > 0);

    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cout << nextMap[y][x] << ' ';
        }
        std::cout << '\n';
    }
    return (0);
}
