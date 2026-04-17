#include <iostream>

const int MAX_SIZE = 499;

int size, outDust;
int map[MAX_SIZE][MAX_SIZE];

void    spreadDust(int y, int x, int goDir)
{
    static const int dd[2][10] = {
        {-1, -1, -1, -2, 1, 1, 1, 2, 0, 0}, // dy
        {-1, 0, 1, 0, -1, 0, 1, 0, -2, -1} // dx
    };
    static const int dirSize = sizeof(dd[0]) / sizeof(dd[0][0]);
    static const int ratio[] = {
        10, 7, 1, 2, 10, 7, 1, 2, 5, 100
    };
    static const int ySign[] = {
        1, -1, 1, 1
    };
    static const int xSign[] = {
        1, 1, -1, 1
    };

    int yIdx = (goDir & 1);
    int xIdx = yIdx ^ 1;
    int &remainDust = map[y][x];
    int originDust = remainDust;

    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dd[yIdx][dir] * ySign[goDir];
        int nextX = x + dd[xIdx][dir] * xSign[goDir];
        int nextDust = originDust * ratio[dir] / 100;

        if (dir == dirSize - 1)
        {
            nextDust = remainDust;
        }

        if (!(0 <= nextY && nextY < size)
            || !(0 <= nextX && nextX < size))
        {
            outDust += nextDust;
        }
        else
        {
            map[nextY][nextX] += nextDust;
        }

        remainDust -= nextDust;
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    const int dy[] = {0, 1, 0, -1};
    const int dx[] = {-1, 0, 1, 0};
    const int dirSize = sizeof(dy) / sizeof(dy[0]);

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    int y = size / 2;
    int x = y;
    int dir = 0;
    int moved = 0, moveCnt = 1;
    while (y != 0 || x != -1)
    {
        y += dy[dir];
        x += dx[dir];
        ++moved;

        spreadDust(y, x, dir);
        if (moved == moveCnt)
        {
            moved = 0;
            moveCnt += (dir & 1);
            dir = (dir + 1) % dirSize;
        }
    }

    std::cout << outDust << '\n';
    return 0;
}
