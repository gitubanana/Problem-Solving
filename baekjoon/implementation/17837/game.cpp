#include <iostream>
#include <list>

enum e_space
{
    EMPTY = 0,
    REVERSE,
    WALL
};

const int MAX = 12;
const int STOP_HEIGHT = 4;
const int HORSE_SIZE = 10;

struct t_horse
{
    int y, x;
    int dirIdx;
};

int top[MAX][MAX];
int stack[MAX][MAX][HORSE_SIZE];

inline static void pushHorse(int y, int x, int horseNum)
{
    stack[y][x][top[y][x]++] = horseNum;
}

inline static int popHorse(int y, int x)
{
    return stack[y][x][--top[y][x]];
}

inline static int findHorsePos(int y, int x, int toFind)
{
    for (int i = 0; i < top[y][x]; ++i)
    {
        if (stack[y][x][i] == toFind)
            return (i);
    }
    return (-1);
}

int size;
int map[MAX][MAX];
int maxHeight = 1;
t_horse horse[HORSE_SIZE];

int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

inline int getOpposite(int dirIdx)
{
    switch (dirIdx)
    {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 3;
    }
    return 2;
}

void reverse(int toMove, int nextY, int nextX)
{
    t_horse &cur = horse[toMove];
    int pos = findHorsePos(cur.y, cur.x, toMove);
    int &curTop = top[cur.y][cur.x];
    int removedHeight = pos;

    while (pos < curTop)
    {
        int popped = popHorse(cur.y, cur.x);

        horse[popped].y = nextY;
        horse[popped].x = nextX;
        pushHorse(nextY, nextX, popped);
    }
    maxHeight = std::max(maxHeight, top[nextY][nextX]);
    curTop = removedHeight;
}

void empty(int toMove, int nextY, int nextX)
{
    t_horse &cur = horse[toMove];
    int pos = findHorsePos(cur.y, cur.x, toMove);
    int *curStack = stack[cur.y][cur.x];
    int &curTop = top[cur.y][cur.x];
    int removedHeight = pos;

    while (pos < curTop)
    {
        int popped = curStack[pos];

        horse[popped].y = nextY;
        horse[popped].x = nextX;
        pushHorse(nextY, nextX, popped);
        ++pos;
    }
    maxHeight = std::max(maxHeight, top[nextY][nextX]);
    curTop = removedHeight;
}

void wall(int toMove)
{
    t_horse &cur = horse[toMove];
    cur.dirIdx = getOpposite(cur.dirIdx);

    int nextY = cur.y + dy[cur.dirIdx];
    int nextX = cur.x + dx[cur.dirIdx];
    if (!(0 <= nextY && nextY < size)
        || !(0 <= nextX && nextX < size)
        || map[nextY][nextX] == WALL)
        return;

    int &nextSpace = map[nextY][nextX];
    switch (nextSpace)
    {
    case REVERSE:
        reverse(toMove, nextY, nextX);
        break;
    default:
        empty(toMove, nextY, nextX);
        break;
    }
}

void moveHorse(int toMove)
{
    t_horse &cur = horse[toMove];
    int nextY = cur.y + dy[cur.dirIdx];
    int nextX = cur.x + dx[cur.dirIdx];

    if (!(0 <= nextY && nextY < size)
        || !(0 <= nextX && nextX < size))
    {
        wall(toMove);
        return;
    }

    int &nextSpace = map[nextY][nextX];
    switch (nextSpace)
    {
    case WALL:
        wall(toMove);
        break;
    case REVERSE:
        reverse(toMove, nextY, nextX);
        break;
    default:
        empty(toMove, nextY, nextX);
        break;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int horseCnt;

    std::cin >> size >> horseCnt;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
            std::cin >> map[y][x];
    }

    int horseY, horseX, dirIdx;
    for (int i = 0; i < horseCnt; ++i)
    {
        std::cin >> horseY >> horseX >> dirIdx;
        --horseY, --horseX, --dirIdx;

        horse[i] = {horseY, horseX, dirIdx};
        pushHorse(horseY, horseX, i);
    }

    int ans = 0;
    while (ans <= 1000 && maxHeight < STOP_HEIGHT)
    {
        for (int i = 0; i < horseCnt && maxHeight < STOP_HEIGHT; ++i)
            moveHorse(i);

        ++ans;
    }

    std::cout << (ans == 1001 ? -1 : ans) << '\n';
    return (0);
}
