#include <iostream>
#include <algorithm>

const int MAX_SIZE = 50;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize, roomCnt, maxBreakSize;
int roomSize[MAX_SIZE * MAX_SIZE + 1];
int roomNum[MAX_SIZE][MAX_SIZE];
int map[MAX_SIZE][MAX_SIZE];

inline bool isWall(int space, int dir)
{
    return (space & (1 << dir));
}

void    dfs(int y, int x, int &curRoomSize)
{
    ++curRoomSize;
    roomNum[y][x] = roomCnt;

    int &curSpace = map[y][x];
    for (int dir = 0; dir < dirSize; ++dir)
    {
        if (isWall(curSpace, dir))
            continue ;

        int nextY = y + dy[dir];
        int nextX = x + dx[dir];
    
        if (roomNum[nextY][nextX])
            continue ;

        dfs(nextY, nextX, curRoomSize);
    }
}

void    findBreakSize(void)
{
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            for (int dir = 0; dir < dirSize; ++dir)
            {
                int nextY = y + dy[dir];
                int nextX = x + dx[dir];

                if (!(0 <= nextY && nextY < ySize)
                    || !(0 <= nextX && nextX < xSize)
                    || roomNum[y][x] == roomNum[nextY][nextX])
                    continue ;

                maxBreakSize = std::max(
                    maxBreakSize,
                    roomSize[roomNum[y][x]] + roomSize[roomNum[nextY][nextX]]
                );
            }
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> xSize >> ySize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            if (roomNum[y][x])
                continue ;

            int curRoomSize = 0;

            ++roomCnt;
            dfs(y, x, curRoomSize);
            roomSize[roomCnt] = curRoomSize;
        }
    }

    findBreakSize();

    std::cout << roomCnt << '\n';
    std::cout << *std::max_element(roomSize + 1, roomSize + 1 + roomCnt) << '\n';
    std::cout << maxBreakSize << '\n';
    return (0);
}
