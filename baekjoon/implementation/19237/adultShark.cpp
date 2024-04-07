#include <iostream>

enum e_space
{
    EMPTY = 0
};

struct t_scent
{
    int from;
    int created;
};

struct t_shark
{
    int dir;
    int y, x;
    int priority[5][4];
    bool isOut;
};

const int MAX = 20;
const int dy[] = {0, -1, 1, 0, 0};
const int dx[] = {0, 0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]) - 1;

int time_;
int mapSize;
int sharkCnt;
int scentTime;
int remainingShark;
int spaceMap[MAX][MAX];
t_scent scentMap[MAX][MAX];
t_shark sharkArr[MAX * MAX + 1];

void    sprayScent(void)
{
    for (int num = 1; num <= sharkCnt; ++num)
    {
        t_shark &cur = sharkArr[num];

        if (cur.isOut)
            continue ;

        scentMap[cur.y][cur.x].from = num;
        scentMap[cur.y][cur.x].created = time_;
    }
}

inline bool isEmpty(int y, int x)
{
    t_scent &toCheck = scentMap[y][x];

    if (toCheck.from == 0)
        return (true);
    return (time_ - toCheck.created >= scentTime);
}

inline void moveByPriority(t_shark &toMove, int num)
{
    int myScentY = -1, myScentX;
    int myScentDir;

    for (int i = 0; i < dirSize; ++i)
    {
        int &moveDir = toMove.priority[toMove.dir][i];
        int nextY = toMove.y + dy[moveDir];
        int nextX = toMove.x + dx[moveDir];

        if (!(0 <= nextY && nextY < mapSize)
            || !(0 <= nextX && nextX < mapSize))
            continue ;

        if (isEmpty(nextY, nextX))
        {
            toMove.y = nextY;
            toMove.x = nextX;
            toMove.dir = moveDir;
            return ;
        }
        else if (scentMap[nextY][nextX].from == num && myScentY == -1)
        {
            myScentY = nextY;
            myScentX = nextX;
            myScentDir = moveDir;
        }
    }
    if (myScentY == -1)
    {
        std::cerr << "자신의 냄새가 있는 칸이 없음" << '\n';
    }
    toMove.y = myScentY;
    toMove.x = myScentX;
    toMove.dir = myScentDir;
}

void    moveSharks(void)
{
    for (int num = 1; num <= sharkCnt; ++num)
    {
        t_shark &cur = sharkArr[num];

        if (cur.isOut)
            continue ;

        spaceMap[cur.y][cur.x] = EMPTY;
        moveByPriority(cur, num);

        int &nextSpace = spaceMap[cur.y][cur.x];
        if (nextSpace == EMPTY)
        {
            nextSpace = num;
        }
        else
        {
            cur.isOut = true;
            --remainingShark;
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> mapSize >> sharkCnt >> scentTime;
    for (int y = 0; y < mapSize; ++y)
    {
        for (int x = 0; x < mapSize; ++x)
        {
            int &curSpace = spaceMap[y][x];

            std::cin >> curSpace;
            if (curSpace != EMPTY)
            {
                sharkArr[curSpace].y = y;
                sharkArr[curSpace].x = x;
            }
        }
    }
    for (int num = 1; num <= sharkCnt; ++num)
    {
        std::cin >> sharkArr[num].dir;
    }
    for (int num = 1; num <= sharkCnt; ++num)
    {
        for (int from = 1; from <= dirSize; ++from)
        {
            for (int to = 0; to < dirSize; ++to)
            {
                std::cin >> sharkArr[num].priority[from][to];
            }
        }
    }

    remainingShark = sharkCnt;
    while (remainingShark > 1 && time_ < 1000)
    {
        sprayScent();
        moveSharks();
        ++time_;
    }

    std::cout << (remainingShark > 1 && time_ == 1000 ? -1 : time_) << '\n';
    return (0);
}
