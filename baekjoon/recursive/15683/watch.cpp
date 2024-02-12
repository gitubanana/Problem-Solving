#include <iostream>
#include <climits>
#include <functional>

enum e_space
{
    EMPTY = 0,
    WALL = 6
};

struct t_pos
{
    int y, x;
};

const int MAX = 8;

int map[MAX][MAX];
t_pos cctvs[MAX];
int ySize, xSize, cctvCnt;
int min = INT_MAX;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int dirSize[] = {0, 4, 2, 4, 4, 1};
int dirCnt[] = {0, 1, 2, 2, 3, 4};
int step[] = {0, 0, 2, 1, 1, 1};

template <typename Func>
void doSomeThing(t_pos &cctv, int dir, int type, Func &f)
{
    for (int i = 0; i < dirCnt[type]; ++i)
    {
        t_pos toWatch = {cctv.y + dy[dir], cctv.x + dx[dir]};
        while (true)
        {
            if (!(0 <= toWatch.y && toWatch.y < ySize)
                || !(0 <= toWatch.x && toWatch.x < xSize)
                || map[toWatch.y][toWatch.x] == WALL)
                break ;

            int &space = map[toWatch.y][toWatch.x];
            if (space <= EMPTY)
                space = f(space, type);

            toWatch.y += dy[dir];
            toWatch.x += dx[dir];
        }
        dir += step[type];
        dir %= 4;
    }
}

void back_tracking(int depth)
{
    static std::plus<int> plusFunc;
    static std::minus<int> minusFunc;

    if (depth == cctvCnt)
    {
        int blindSpotCnt = 0;

        for (int y = 0; y < ySize; ++y)
        {
            for (int x = 0; x < xSize; ++x)
            {
                blindSpotCnt += (map[y][x] == EMPTY);
            }
        }
        min = std::min(min, blindSpotCnt);
        return ;
    }

    t_pos &cctv = cctvs[depth];
    int type = map[cctv.y][cctv.x];
    for (int i = 0; i < dirSize[type]; ++i)
    {
        doSomeThing(cctv, i, type, minusFunc);
        back_tracking(depth + 1);
        doSomeThing(cctv, i, type, plusFunc);
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
            int &space = map[y][x];

            std::cin >> space;
            if (space != EMPTY && space != WALL)
                cctvs[cctvCnt++] = {y, x};
        }
    }

    back_tracking(0);

    std::cout << min << '\n';
    return (0);
}
