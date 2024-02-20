#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>

struct t_cnt
{
    int num;
    int cnt;

    inline bool operator<(const t_cnt &other) const
    {
        if (cnt == other.cnt)
            return (num < other.num);
        return (cnt < other.cnt);
    }
};

const int MAX = 100;
const int FIRST_SIZE = 3;

int map[MAX + 1][MAX + 1];
int wantY, wantX, wantValue;
int ySize = 3, xSize = 3;
int yNumCnt[MAX + 1][MAX + 1];
int xNumCnt[MAX + 1][MAX + 1];
t_cnt arr[MAX + 1];

void    printCnt()
{
    std::cout << "~~~~~~~~~~~~~~~~~~~~" << '\n';
    std::cout << "(num, cnt)" << '\n';
    std::cout << "yCnt : " << '\n';
    for (int y = 0; y < ySize; ++y)
    {
        std::cout << "y : " << y << " = ";
        for (int num = 1; num <= MAX; ++num)
        {
            if (yNumCnt[y][num] == 0)
                continue ;

            std::cout << "(" << num << ", " << yNumCnt[y][num] << ")" << ", ";
        }
        std::cout << '\n';
    }
    std::cout << "~~~~~~~~~~~~~~~~~~~~" << '\n';

    std::cout << "~~~~~~~~~~~~~~~~~~~~" << '\n';
    std::cout << "(num, cnt)" << '\n';
    std::cout << "xCnt : " << '\n';
    for (int x = 0; x < xSize; ++x)
    {
        std::cout << "x : " << x << " = ";
        for (int num = 1; num <= MAX; ++num)
        {
            if (xNumCnt[x][num] == 0)
                continue ;

            std::cout << "(" << num << ", " << xNumCnt[x][num] << ")" << ", ";
        }
        std::cout << '\n';
    }
    std::cout << "~~~~~~~~~~~~~~~~~~~~" << '\n';
}

void    R()
{
    // xSize 증가 (100넘으면 100으로 줄이기)
    for (int y = 0; y < ySize; ++y)
    {
        int idx = 0;
        int *curCnt = yNumCnt[y];

        for (int num = 1; num <= MAX; ++num)
        {
            if (curCnt[num] == 0)
                continue ;

            arr[idx].num = num;
            arr[idx++].cnt = curCnt[num];
        }

        std::sort(arr, arr + idx);
        memset(yNumCnt[y], 0, sizeof(yNumCnt[y]));
        for (int x = 0; x < xSize; ++x)
        {
            --xNumCnt[x][map[y][x]];
            map[y][x] = 0;
        }

        int newXsize = 0;
        for (int i = 0; i < idx; ++i)
        {
            t_cnt &cur = arr[i];

            if (newXsize < MAX)
            {
                ++yNumCnt[y][cur.num];
                ++xNumCnt[newXsize][cur.num];
                map[y][newXsize++] = cur.num;
            }

            if (newXsize < MAX)
            {
                ++yNumCnt[y][cur.cnt];
                ++xNumCnt[newXsize][cur.cnt];
                map[y][newXsize++] = cur.cnt;
            }

            if (newXsize == MAX)
                break ;
        }
        xSize = std::max(xSize, newXsize);
    }
}

void    C()
{

    // ySize 증가 (100넘으면 100으로 줄이기)
    for (int x = 0; x < xSize; ++x)
    {
        int idx = 0;
        int *curCnt = xNumCnt[x];

        for (int num = 1; num <= MAX; ++num)
        {
            if (curCnt[num] == 0)
                continue ;

            arr[idx].num = num;
            arr[idx++].cnt = curCnt[num];
        }

        std::sort(arr, arr + idx);
        memset(xNumCnt[x], 0, sizeof(xNumCnt[x]));
        for (int y = 0; y < ySize; ++y)
        {
            --yNumCnt[y][map[y][x]];
            map[y][x] = 0;
        }

        int row = 0;
        for (int i = 0; i < idx; ++i)
        {
            t_cnt &cur = arr[i];

            if (row < MAX)
            {
                ++xNumCnt[x][cur.num];
                ++yNumCnt[row][cur.num];
                map[row++][x] = cur.num;
            }

            if (row < MAX)
            {
                ++xNumCnt[x][cur.cnt];
                ++yNumCnt[row][cur.cnt];
                map[row++][x] = cur.cnt;
            }

            if (row == MAX)
                break ;
        }
        ySize = std::max(ySize, row);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> wantY >> wantX >> wantValue;
    --wantY, --wantX;
    for (int y = 0; y < FIRST_SIZE; ++y)
    {
        for (int x = 0; x < FIRST_SIZE; ++x)
        {
            int &cur = map[y][x];

            std::cin >> cur;
            ++yNumCnt[y][cur];
            ++xNumCnt[x][cur];
        }
    }

    int ans = 0;
    while (ans <= 100 && map[wantY][wantX] != wantValue)
    {
        if (ySize >= xSize)
            R();
        else
            C();
        ++ans;
    }

    std::cout << (ans == 101 ? -1 : ans) << '\n';
    return (0);
}
