#include <iostream>
#include <climits>
#include <vector>
#define CURMAP map[curIdx]
#define NEXTMAP map[nextIdx]

enum e_space
{
    PASS = INT_MAX
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 50;
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size;
int curIdx, nextIdx;
int map[2][MAX_SIZE][MAX_SIZE];
std::vector<t_pos> tonics;

inline bool isBound(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < size)
            && (0 <= pos.x && pos.x < size));
}

inline void    moveTonics(int dir, int dist)
{
    for (t_pos &cur : tonics)
    {
        cur.y = cur.y + dy[dir] * dist;
        cur.x = cur.x + dx[dir] * dist;

        if (cur.y < 0)
        {
            cur.y += size;
        }
        else if (cur.y >= size)
        {
            cur.y -= size;
        }

        if (cur.x < 0)
        {
            cur.x += size;
        }
        else if (cur.x >= size)
        {
            cur.x -= size;
        }

        ++CURMAP[cur.y][cur.x];
    }
}

void    makeNewTonics(void)
{
    nextIdx = curIdx ^ 1;

    for (const t_pos &cur : tonics)
    {
        int plus = 0;

        for (int dir = 1; dir < dirSize; dir += 2)
        {
            t_pos check = {
                cur.y + dy[dir],
                cur.x + dx[dir]
            };

            if (!isBound(check))
                continue ;

            plus += (CURMAP[check.y][check.x] >= 1);
        }

        NEXTMAP[cur.y][cur.x] = CURMAP[cur.y][cur.x] + plus;
        CURMAP[cur.y][cur.x] = PASS;
    }

    tonics.clear();
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            int &curSpace = CURMAP[y][x];
            if (curSpace == PASS)
                continue ;

            if (curSpace >= 2)
            {
                curSpace -= 2;
                tonics.push_back({y, x});
            }

            NEXTMAP[y][x] = curSpace;
        }
    }

    curIdx = nextIdx;
}

int getHeightSum(void)
{
    int sum = 0;

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            sum += CURMAP[y][x];
        }
    }
    return (sum);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int year;

    std::cin >> size >> year;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> CURMAP[y][x];
        }
    }

    for (int y = size - 1, cnt = 3; --cnt; --y)
    {
        tonics.push_back({y, 0});
        tonics.push_back({y, 1});
    }

    while (year--)
    {
        int dir, dist;

        std::cin >> dir >> dist;
        --dir;

        moveTonics(dir, dist % size);
        makeNewTonics();
    }

    std::cout << getHeightSum() << '\n';
    return 0;
}