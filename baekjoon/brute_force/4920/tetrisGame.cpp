#include <iostream>
#include <cstring>
#include <climits>

const int MAX_SIZE = 100;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size, maxSum;
int map[MAX_SIZE][MAX_SIZE];

inline bool isBound(int y, int x)
{
    return ((0 <= y && y < size)
            && (0 <= x && x < size));
}

void    tetrisFour(int y, int x, int firstDir, int curSum)
{
    static const int GO_CNT = 2;
    static const int dd[][GO_CNT] = {
        {1, -1},
        {1, 1},
        {0, 1},
        {0, 0}
    };
    for (int m = 0; m < dirSize; ++m)
    {
        int dir = firstDir;
        int cmpSum = curSum;
        int nextY = y;
        int nextX = x;

        for (int d = 0; d < GO_CNT; ++d)
        {
            dir = (dir + dd[m][d] + dirSize) % dirSize;
            nextY += dy[dir];
            nextX += dx[dir];

            if (!isBound(nextY, nextX))
            {
                cmpSum = INT_MIN;
                break ;
            }

            cmpSum += map[nextY][nextX];
        }

        maxSum = std::max(maxSum, cmpSum);
    }
}


void calculateMax(void)
{
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            int addCnt = 0;
            int flowerSum = map[y][x];
            int flowerMin = INT_MAX;

            for (int dir = 0; dir < dirSize; ++dir)
            {
                int nextY = y + dy[dir];
                int nextX = x + dx[dir];

                if (!isBound(nextY, nextX))
                    continue ;

                ++addCnt;
                flowerSum += map[nextY][nextX];
                flowerMin = std::min(flowerMin, map[nextY][nextX]);

                tetrisFour(nextY, nextX, dir, map[y][x] + map[nextY][nextX]);
            }

            switch (addCnt)
            {
            case 4:
                maxSum = std::max(maxSum, flowerSum - flowerMin);
                break;
            case 3:
                maxSum = std::max(maxSum, flowerSum);
                break;
            }
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    for (int t = 1; ; ++t)
    {
        std::cin >> size;
        if (size == 0)
            break ;

        for (int y = 0; y < size; ++y)
        {
            for (int x = 0; x < size; ++x)
            {
                std::cin >> map[y][x];
            }
        }

        maxSum = INT_MIN;
        calculateMax();
        std::cout << t << ". " << maxSum << '\n';
    }
    return (0);
}
