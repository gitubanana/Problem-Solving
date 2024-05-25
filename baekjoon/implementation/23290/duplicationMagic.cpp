#include <iostream>
#include <vector>
#define START_TIME 3
#define SCENT_REMOVE_TIME 2
#define CURMAP map[curIdx]
#define NEXTMAP map[nextIdx]

struct t_pos
{
    int y, x;

    inline bool operator!=(const t_pos &other) const
    {
        return (this->y != other.y || this->x != other.x);
    }
};

const int SIZE = 4;
const int SHARK_MOVE_CNT = 3;
const int fDy[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int fDx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int fDirSize = sizeof(fDy) / sizeof(fDy[0]);
const int sDy[] = {-1, 0, 1, 0};
const int sDx[] = {0, -1, 0, 1};
const int sDirSize = sizeof(sDy) / sizeof(sDy[0]);

int curTime;
int curIdx, nextIdx;
int scentTime[SIZE][SIZE];
int visited[SIZE][SIZE];
std::vector<int> map[2][SIZE][SIZE];
t_pos shark;
int maxEatCnt;
int cmpDirs[SHARK_MOVE_CNT];
int moveDirs[SHARK_MOVE_CNT];

inline std::istream &operator>>(std::istream &in, t_pos &input)
{
    in >> input.y >> input.x;
    --input.y, --input.x;
    return (in);
}

inline bool isFishScent(const t_pos &pos)
{
    return (curTime - scentTime[pos.y][pos.x] <= SCENT_REMOVE_TIME);
}

void moveFish(const t_pos &cur, int nextDir)
{
    for (int i = 0; i < fDirSize; ++i)
    {
        t_pos next = {cur.y + fDy[nextDir], cur.x + fDx[nextDir]};

        if ((0 <= next.y && next.y < SIZE)
            && (0 <= next.x && next.x < SIZE)
            && !isFishScent(next)
            && next != shark)
        {
            NEXTMAP[next.y][next.x].push_back(nextDir);
            return ;
        }
        nextDir = (nextDir == 0 ? fDirSize - 1 : nextDir - 1);
    }

    NEXTMAP[cur.y][cur.x].push_back(nextDir);
}

void    moveFishes(void)
{
    t_pos cur;

    for (cur.y = 0; cur.y < SIZE; ++cur.y)
    {
        for (cur.x = 0; cur.x < SIZE; ++cur.x)
        {
            for (const int &fishDir : CURMAP[cur.y][cur.x])
            {
                moveFish(cur, fishDir);
            }
        }
    }
}

void    backTracking(t_pos cur, int curEatCnt=0, int depth=0)
{
    if (depth == SHARK_MOVE_CNT)
    {
        if (maxEatCnt < curEatCnt)
        {
            maxEatCnt = curEatCnt;
            for (int i = 0; i < SHARK_MOVE_CNT; ++i)
            {
                moveDirs[i] = cmpDirs[i];
            }
        }
        return ;
    }

    for (int dir = 0; dir < sDirSize; ++dir)
    {
        t_pos next = {cur.y + sDy[dir], cur.x + sDx[dir]};

        if (!(0 <= next.y && next.y < SIZE)
            || !(0 <= next.x && next.x < SIZE))
            continue ;

        int nextEatCnt = curEatCnt +
            (NEXTMAP[next.y][next.x].size() * !visited[next.y][next.x]);

        ++visited[next.y][next.x];
        cmpDirs[depth] = dir;
        backTracking(
            next,
            nextEatCnt,
            depth + 1
        );
        --visited[next.y][next.x];
    }
}

void    moveShark(void)
{
    maxEatCnt = -1;
    backTracking(shark);

    for (int i = 0; i < SHARK_MOVE_CNT; ++i)
    {
        const int &dir = moveDirs[i];

        shark.y += sDy[dir];
        shark.x += sDx[dir];

        if (NEXTMAP[shark.y][shark.x].size())
        {
            scentTime[shark.y][shark.x] = curTime;
        }
        NEXTMAP[shark.y][shark.x].clear();
    }
}

void    duplicateFishes(void)
{
    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            for (const int &fishDir : CURMAP[y][x])
            {
                NEXTMAP[y][x].push_back(fishDir);
            }

            CURMAP[y][x].clear();
        }
    }
}

int countFishes(void)
{
    int cnt = 0;

    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            cnt += CURMAP[y][x].size();
        }
    }
    return (cnt);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int fishDir;
    t_pos fishPos;
    int fishCnt, practiceTime;

    std::cin >> fishCnt >> practiceTime;
    while (fishCnt--)
    {
        std::cin >> fishPos >> fishDir;
        --fishDir;
        CURMAP[fishPos.y][fishPos.x].push_back(fishDir);
    }
    std::cin >> shark;

    curTime = START_TIME;
    practiceTime += START_TIME;
    while (curTime < practiceTime)
    {
        nextIdx = (curIdx + 1) % 2;
        moveFishes();
        moveShark();
        duplicateFishes();
        curIdx = nextIdx;
        ++curTime;
    }

    std::cout << countFishes() << '\n';
    return (0);
}
