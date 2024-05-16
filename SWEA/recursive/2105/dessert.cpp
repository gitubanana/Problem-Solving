#include <iostream>

const int MAX_SIZE = 20;
const int MAX_DESSERT = 101;

int size;
int maxCnt;
int startY, startX;
int map[MAX_SIZE][MAX_SIZE];
int eaten[MAX_DESSERT];

inline bool isBound(int y, int x)
{
    return ((0 <= y && y < size)
            && (0 <= x && x < size));
}

void    back_tracking(int y, int x, int dir=0, int curCnt=1)
{
    static const int dy[] = {1, 1, -1, -1};
    static const int dx[] = {1, -1, -1, 1};
    static const int dirSize = sizeof(dy) / sizeof(dy[0]);

    if (!isBound(y, x))
        return ;

    int &curDessert = map[y][x];
    if (dir == dirSize - 1)
    {
        if (y == startY && x == startX)
        {
            maxCnt = std::max(maxCnt, curCnt - 1);
            return ;
        }
    }

    if (eaten[curDessert])
        return ;

    eaten[curDessert] = true;

    back_tracking(y + dy[dir], x + dx[dir], dir, curCnt + 1);

    if (dir != dirSize - 1)
    {
        ++dir;
        back_tracking(y + dy[dir], x + dx[dir], dir, curCnt + 1);
    }
    eaten[curDessert] = false;
}

void findMaxDessert(void)
{
    int size_1 = size - 1;

    maxCnt = 0;
    for (startY = 0; startY < size_1; ++startY)
    {
        for (startX = 1; startX < size_1; ++startX)
        {
            back_tracking(startY, startX);
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        std::cin >> size;
        for (int y = 0; y < size; ++y)
        {
            for (int x = 0; x < size; ++x)
            {
                std::cin >> map[y][x];
            }
        }

        findMaxDessert();
        std::cout << "#" << t << ' ' << (maxCnt == 0 ? -1 : maxCnt) << '\n';
    }
    return (0);
}
