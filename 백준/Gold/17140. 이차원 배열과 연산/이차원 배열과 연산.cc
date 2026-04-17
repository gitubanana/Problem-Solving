#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

struct t_freq
{
    int num;
    int cnt;

    inline bool operator<(const t_freq &other) const
    {
        if (this->cnt == other.cnt)
        {
            return (this->num < other.num);
        }

        return (this->cnt < other.cnt);
    }
};

const int MAX_SIZE = 100;
const int MAX_TIME = 100;
const int MAX_NUM = 100;

int ySize = 3, xSize = 3;
int map[MAX_SIZE][MAX_SIZE];
int cnt[MAX_NUM + 1];
std::vector<t_freq> sorted;

void    sortRow(void)
{
    int maxXsize = 0;

    for (int y = 0; y < ySize; ++y)
    {
        memset(cnt, 0, sizeof(cnt));
        for (int x = 0; x < xSize; ++x)
        {
            int &cur = map[y][x];

            ++cnt[cur];
        }

        sorted.clear();
        for (int num = 1; num <= MAX_NUM; ++num)
        {
            int &curCnt = cnt[num];
            if (curCnt == 0)
                continue ;

            sorted.push_back({num, curCnt});
        }

        int curXsize = sorted.size() * 2;
        if (curXsize > MAX_SIZE)
        {
            curXsize = MAX_SIZE;
        }
        maxXsize = std::max(maxXsize, curXsize);

        int x = 0;

        std::sort(sorted.begin(), sorted.end());
        for (const t_freq &cur : sorted)
        {
            map[y][x++] = cur.num;
            map[y][x++] = cur.cnt;
            if (x == MAX_SIZE)
                break ;
        }

        for (; x < xSize; ++x)
        {
            map[y][x] = 0;
        }
    }

    xSize = maxXsize;
}

void    sortCol(void)
{
    int maxYsize = 0;

    for (int x = 0; x < xSize; ++x)
    {
        memset(cnt, 0, sizeof(cnt));
        for (int y = 0; y < ySize; ++y)
        {
            int &cur = map[y][x];

            ++cnt[cur];
        }

        sorted.clear();
        for (int num = 1; num <= MAX_NUM; ++num)
        {
            int &curCnt = cnt[num];
            if (curCnt == 0)
                continue ;

            sorted.push_back({num, curCnt});
        }

        int curYsize = sorted.size() * 2;
        if (curYsize > MAX_SIZE)
        {
            curYsize = MAX_SIZE;
        }
        maxYsize = std::max(maxYsize, curYsize);

        int y = 0;

        std::sort(sorted.begin(), sorted.end());
        for (const t_freq &cur : sorted)
        {
            map[y++][x] = cur.num;
            map[y++][x] = cur.cnt;
            if (y == MAX_SIZE)
                break ;
        }

        for (; y < ySize; ++y)
        {
            map[y][x] = 0;
        }
    }

    ySize = maxYsize;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int r, c, wantValue;

    std::cin >> r >> c >> wantValue;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    int ans = 0;
    int &target = map[r - 1][c - 1];
    while (target != wantValue)
    {
        if (ans == MAX_TIME)
        {
            ans = -1;
            break ;
        }

        if (ySize >= xSize)
        {
            sortRow();
        }
        else
        {
            sortCol();
        }

        ++ans;
    }

    std::cout << ans << '\n';
    return 0;
}