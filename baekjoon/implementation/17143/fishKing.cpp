#include <iostream>
#include <vector>
#include <map>
#define SIZE first
#define SHARK second

struct t_shark
{
    int y, x;
    int speed;
    int dir;
};

const int MAX = 101;
const int EMPTY = 0;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int fisherPos;
int fishOutSize;
int ySize, xSize;
int map[MAX][MAX];
std::map<int, t_shark> sharks;

inline std::istream &operator>>(std::istream &in, t_shark &input)
{
    in >> input.y >> input.x >> input.speed >> input.dir;
    --input.dir;
    return (in);
}

void    catchFish(void)
{
    for (int y = 1; y <= ySize; ++y)
    {
        int &curSpace = map[y][fisherPos];

        if (curSpace != EMPTY)
        {
            sharks.erase(curSpace);
            fishOutSize += curSpace;
            curSpace = EMPTY;
            break ;
        }
    }
}

void    moveSharks(void)
{
    static std::vector<int> removedSharks;

    for (std::pair<const int, t_shark> &cur : sharks)
    {
        t_shark &shark = cur.SHARK;
        int prevY = shark.y;
        int prevX = shark.x;
        int moveCnt = shark.speed;

        if (shark.speed != 0 && cur.SIZE == map[shark.y][shark.x])
            map[shark.y][shark.x] = EMPTY;
        while (moveCnt)
        {
            int nextY = shark.y + dy[shark.dir] * moveCnt;
            int nextX = shark.x + dx[shark.dir] * moveCnt;

            shark.dir += 1 - 2 * (shark.dir & 1);
            if (nextY > ySize)
            {
                moveCnt -= ySize - shark.y;
                shark.y = ySize;
            }
            else if (nextY < 1)
            {
                moveCnt -= shark.y - 1;
                shark.y = 1;
            }
            else if (nextX > xSize)
            {
                moveCnt -= xSize - shark.x;
                shark.x = xSize;
            }
            else if (nextX < 1)
            {
                moveCnt -= shark.x - 1;
                shark.x = 1;
            }
            else
            {
                shark.y = nextY;
                shark.x = nextX;
                moveCnt = 0;
                shark.dir += 1 - 2 * (shark.dir & 1);
            }
        }

        int &nextSpace = map[shark.y][shark.x];
        if (nextSpace != EMPTY && nextSpace < cur.SIZE)
        {
            removedSharks.push_back(nextSpace);
        }

        nextSpace = cur.SIZE;
    }

    for (const int &sharkSize : removedSharks)
    {
        sharks.erase(sharkSize);
    }
    removedSharks.clear();
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int sharkCnt;
    int sharkSize;
    t_shark shark;

    std::cin >> ySize >> xSize >> sharkCnt;
    while (sharkCnt--)
    {
        std::cin >> shark >> sharkSize;
        sharks[sharkSize] = shark;
        map[shark.y][shark.x] = sharkSize;
    }

    while (fisherPos < xSize)
    {
        ++fisherPos;
        catchFish();
        moveSharks();
    }
    std::cout << fishOutSize << '\n';
    return (0);
}
