#include <iostream>
#include <deque>

enum e_space
{
    EMPTY,
    REVERSE,
    WALL
};

struct t_horse
{
    int y, x;
    int dir;
};

typedef std::deque<int> t_stack;

const int MAP_SIZE = 12 + 1;
const int HORSE_CNT = 10 + 1;
const int STOP_HEIGHT = 4;
const int dy[] = {0, 0, 0, -1, 1};
const int dx[] = {0, 1, -1, 0, 0};

size_t maxHeight = 1;
int mapSize, horseCnt;
int map[MAP_SIZE][MAP_SIZE];
// [0] is floor, [size - 1] is top
t_stack stack[MAP_SIZE][MAP_SIZE];
t_horse horses[HORSE_CNT];

inline std::istream &operator>>(std::istream &in, t_horse &input)
{
    in >> input.y >> input.x >> input.dir;
    return (in);
}

void    moveToEmpty(t_horse &toMove, int nextY, int nextX)
{
    t_stack &curStack = stack[toMove.y][toMove.x];
    t_stack &nextStack = stack[nextY][nextX];

    while (!curStack.empty())
    {
        int toPop = curStack.front();
        t_horse &curHorse = horses[toPop];

        nextStack.push_back(toPop);
        curStack.pop_front();

        curHorse.y = nextY;
        curHorse.x = nextX;
    }

    maxHeight = std::max(maxHeight, nextStack.size());
}

void    moveToReverse(t_horse &toMove, int nextY, int nextX)
{
    t_stack &curStack = stack[toMove.y][toMove.x];
    t_stack &nextStack = stack[nextY][nextX];

    while (!curStack.empty())
    {
        int toPop = curStack.back();
        t_horse &curHorse = horses[toPop];

        nextStack.push_back(toPop);
        curStack.pop_back();

        curHorse.y = nextY;
        curHorse.x = nextX;
    }

    maxHeight = std::max(maxHeight, nextStack.size());
}

inline int getOpposite(int dir)
{
    static const int oppsiteDir[] = {0, 2, 1, 4, 3};
    return oppsiteDir[dir];
}

void    moveToWall(t_horse &toMove, int nextY, int nextX)
{
    toMove.dir = getOpposite(toMove.dir);

    nextY = toMove.y + dy[toMove.dir];
    nextX = toMove.x + dx[toMove.dir];
    if (!(1 <= nextY && nextY <= mapSize)
        || !(1 <= nextX && nextX <= mapSize)
        || map[nextY][nextX] == WALL)
    {
        return ;
    }

    switch (map[nextY][nextX])
    {
    case REVERSE:
        moveToReverse(toMove, nextY, nextX);
        break;
    case EMPTY:
        moveToEmpty(toMove, nextY, nextX);
        break;
    }
}

void    moveHorse(int num)
{
    typedef void (*t_func)(t_horse &, int, int);

    static const t_func funcs[] = {
        &moveToEmpty,
        &moveToReverse,
        &moveToWall
    };
    t_horse &toMove = horses[num];
    t_stack &curStack = stack[toMove.y][toMove.x];

    // number of horse must be the number of the lowest horse 
    if (curStack.front() != num)
    {
        return ;
    }

    int nextY = toMove.y + dy[toMove.dir];
    int nextX = toMove.x + dx[toMove.dir];
    int funcIdx = WALL;

    if ((1 <= nextY && nextY <= mapSize)
        && (1 <= nextX && nextX <= mapSize))
    {
        funcIdx = map[nextY][nextX];
    }

    funcs[funcIdx](toMove, nextY, nextX);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> mapSize >> horseCnt;
    for (int y = 1; y <= mapSize; ++y)
    {
        for (int x = 1; x <= mapSize; ++x)
        {
            std::cin >> map[y][x];
        }
    }
    for (int i = 1; i <= horseCnt; ++i)
    {
        t_horse &curHorse = horses[i];

        std::cin >> curHorse;
        stack[curHorse.y][curHorse.x].push_back(i);
    }

    int turn = 0;
    while (turn < 1000 && maxHeight < STOP_HEIGHT)
    {
        for (int i = 1; i <= horseCnt && maxHeight < STOP_HEIGHT; ++i)
        {
            moveHorse(i);
        }
        ++turn;
    }

    std::cout << (maxHeight < STOP_HEIGHT ? -1 : turn) << '\n';
    return (0);
}
