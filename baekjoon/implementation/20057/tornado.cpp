#include <iostream>
#include <cmath>

struct t_pos
{
    int y;
    int x;

    inline bool operator==(const t_pos &other)
    {
        return (this->y == other.y && this->x == other.x);
    }
};

const int MAX = 499;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {-1, 0, 1, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size;
int outSand;
int map[MAX][MAX];

inline int getXddIdx(int dir)
{
    return (dir & 1);
}

void    scatterSand(t_pos &to, int dir)
{
    const static double ratio[] = {0.01, 0.01, 0.07, 0.07, 0.02, 0.02, 0.1, 0.1, 0.05, 1};
    const static int scatterSize = sizeof(ratio) / sizeof(ratio[0]);
    const static int dd[][scatterSize] = {
        {1, 1, 0, 0, 0, 0, -1, -1, -2, -1},
        {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0}
    };
    const static int xSigns[] = {1, 1, -1, 1};
    const static int ySigns[] = {1, -1, 1, 1};

    int sand = map[to.y][to.x];
    int &origin = map[to.y][to.x];
    int xIdx = getXddIdx(dir);
    int yIdx = !xIdx;

    for (int i = 0; i < scatterSize; ++i)
    {
        t_pos pos = {
            to.y + dd[yIdx][i] * ySigns[dir],
            to.x + dd[xIdx][i] * xSigns[dir]
        };
        int toPlus = ((i == scatterSize - 1)
            ? origin
            : floor(sand * ratio[i])
        );

        if (!(0 <= pos.y && pos.y < size)
            || !(0 <= pos.x && pos.x < size))
        {
            outSand += toPlus;
        }
        else
        {
            map[pos.y][pos.x] += toPlus;
        }

        origin -= toPlus;
    }
}

void    moveTornado(void)
{
    int step = 1;
    int dir = 0;
    t_pos end = {0, 0};
    t_pos cur = {size / 2, size / 2};

    while (true)
    {
        for (int i = 0; i < step; ++i)
        {
            t_pos next = {cur.y + dy[dir], cur.x + dx[dir]};

            scatterSand(next, dir);
            if (next == end)
                return ;

            cur = next;
        }
        step += (dir & 1);
        dir = (dir + 1) % 4;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    moveTornado();
    std::cout << outSand << '\n';
    return (0);
}
