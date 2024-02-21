#include <iostream>
#include <deque>
#include <climits>
#include <algorithm>

struct t_cross
{
    int y;
    int x;
    int size;
};

const int MAX = 100;

int ySize, xSize;
char map[MAX][MAX + 1];
int made[MAX][MAX];
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
std::deque<t_cross> arr;
int crossCnt;

int getCrossSize(int y, int x)
{
    int ret = INT_MAX;

    for (int i = 0; i < 4; ++i)
    {
        int cmp = 0;
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        while ((0 <= nextY && nextY < ySize)
                && (0 <= nextX && nextX < xSize))
        {
            if (map[nextY][nextX] != '*')
                break ;

            nextY += dy[i];
            nextX += dx[i];
            ++cmp;
        }

        ret = std::min(ret, cmp);
    }
    return (ret);
}

void    makeCross(int y, int x, int crossSize, int delta)
{
    made[y][x] += delta;
    for (int i = 0; i < 4; ++i)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        for (int cnt = 0; cnt < crossSize; ++cnt)
        {
            made[nextY][nextX] += delta;
            nextY += dy[i];
            nextX += dx[i];
        }
    }
}

int    getMadeCnt(void)
{
    int ret = 0;

    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
            ret += (made[y][x] != 0);
    }
    return (ret);
}

// 찾으면 exit하기
void    was_back_tracking(int y, int x)
{
    while (true)
    {
        if (y >= ySize && x >= xSize)
            break ;

        if (x >= xSize)
        {
            ++y;
            x = 0;
        }

        if (map[y][x] == '*')
        {
            // 가능한 십자가가 있으면 -> arr.push_back()
            int crossSize = getCrossSize(y, x);
            if (crossSize > 0)
            {
                makeCross(y, x, crossSize, 1);
                arr.push_back({y, x, crossSize});
            }
        }
        ++x;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
        for (int x = 0; x < xSize; ++x)
            crossCnt += (map[y][x] == '*');
    }

    was_back_tracking(0, 0);
    if (getMadeCnt() == crossCnt)
    {
        std::cout << arr.size() << '\n';
        for (t_cross &cur : arr)
        {
            std::cout << cur.y + 1 << ' ' << cur.x + 1 << ' ' << cur.size << '\n';
        }
    }
    else
        std::cout << "-1" << '\n';
    return (0);
}
