#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>

const int MAX_SIZE = 20;
const int DISTRICT_CNT = 5;

int size;
int dist[2];
int vertex[2];
int human[MAX_SIZE][MAX_SIZE];
bool isFour[MAX_SIZE][MAX_SIZE];
int district[DISTRICT_CNT];

void    dfs(int y, int x)
{
    static const int dy[] = {1, 0, 0};
    static const int dx[] = {0, -1, 1};
    static const int dirSize = sizeof(dy) / sizeof(dy[0]);

    isFour[y][x] = true;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (isFour[nextY][nextX])
            continue ;

        dfs(nextY, nextX);
    }
}

void    setTrue(int &y, int &x, int step, int dir)
{
    static const int dy[] = {1, 1, -1, -1, 1};
    static const int dx[] = {-1, 1, 1, -1, 1};

    while (step--)
    {
        isFour[y][x] = true;
        y += dy[dir];
        x += dx[dir];
    }
}

void    setIsFour(void)
{
    static const int dirSize = 4;

    int y = vertex[0];
    int x = vertex[1];
    for (int dir = 0; dir < dirSize; ++dir)
    {
        setTrue(y, x, dist[(dir & 1 != 0)], dir);
    }

    int setY = vertex[0] + 1;
    int setX = vertex[1];
    if (dist[0] == 1 || dist[1] == 1)
    {
        bool isD2 = (dist[0] == 1);

        setTrue(setY, setX, dist[isD2], isD2 * dirSize);
    }
    else
    {
        dfs(setY, setX);
    }
}

inline int getDistrictNum(int y, int x)
{
    int &vY = vertex[0];
    int &vX = vertex[1];
    int &d1 = dist[0];
    int &d2 = dist[1];

    if (isFour[y][x])
        return (4);

    if (y < vY + d1 && x <= vX)
        return (0);

    if (y <= vY + d2 && vX < x)
        return (1);

    if (vY + d1 <= y && x < vX - d1 + d2)
        return (2);

    return (3);
}

int getSmallDiff()
{
    memset(isFour, false, sizeof(isFour));
    setIsFour();
    for (int i = 0; i < DISTRICT_CNT; ++i)
    {
        district[i] = 0;
    }

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            district[getDistrictNum(y, x)] += human[y][x];
        }
    }

    return (*std::max_element(district, district + DISTRICT_CNT)
            - *std::min_element(district, district + DISTRICT_CNT));
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> human[y][x];
        }
    }

    int ans = INT_MAX;

    int &y = vertex[0];
    int &x = vertex[1];
    for ( ; y < size - 2; ++y)
    {
        for (x = 1; x < size - 1; ++x)
        {
            int &d1 = dist[0];
            int &d2 = dist[1];

            d1 = y + (y == 0);
            while (d1 > 0)
            {
                d2 = 1;
                while (y + d1 + d2 < size
                        && x - d1 + d2 + d1 < size)
                {
                    ans = std::min(
                        ans,
                        getSmallDiff()
                    );
                    ++d2;
                }
                --d1;
            }

            d2 = size - x - 1;
            while (d2 > 0)
            {
                d1 = 1;
                while (y + d1 + d2 < size
                        && x + d2 - d1 - d2 >= 0)
                {
                    ans = std::min(
                        ans,
                        getSmallDiff()
                    );
                    ++d1;
                }
                --d2;
            }
        }
    }

    std::cout << ans << '\n';
    return (0);
}
