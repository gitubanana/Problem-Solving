#include <iostream>
#include <cstring>
#include <vector>
#define CURMAP map[curIdx]
#define NEXTMAP map[nextIdx]

struct t_pos
{
    int y, x;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }

    inline bool operator!=(const t_pos &other) const
    {
        return !(*this == other);
    }
};

const int SIZE = 4;
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int maxEat;
t_pos pacMan;
int curTime;
int curIdx, nextIdx;
std::vector<t_pos> ate, cmp;
int visited[SIZE][SIZE];
int deadTime[SIZE][SIZE];
int map[2][SIZE][SIZE][dirSize];

inline std::istream &operator>>(std::istream &cin, t_pos &input)
{
    cin >> input.y >> input.x;
    --input.y, --input.x;
    return (cin);
}

inline bool inRange(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < SIZE)
            && (0 <= pos.x && pos.x < SIZE));
}

inline bool isDead(const t_pos &pos)
{
    static const int LAST_TIME = 2;

    int &cmpTime = deadTime[pos.y][pos.x];
    if (cmpTime == 0)
        return (false);

    return (curTime - cmpTime <= LAST_TIME);
}

void    moveMonsters(void)
{
    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            for (int dir = 0; dir < dirSize; ++dir)
            {
                int curDir = dir;
                int dirCnt = dirSize;
                t_pos next = {y, x};

                while (dirCnt--)
                {
                    t_pos check = {
                        y + dy[curDir],
                        x + dx[curDir]
                    };

                    if (inRange(check)
                        && check != pacMan
                        && !isDead(check))
                    {
                        next = check;
                        break ;
                    }

                    curDir = (curDir + dirSize - 1) % dirSize;
                }

                NEXTMAP[next.y][next.x][curDir] += CURMAP[y][x][dir];
            }
        }
    }
}

int getNextEat(const t_pos &pos)
{
    int eat = 0;

    for (int dir = 0; dir < dirSize; ++dir)
    {
        eat += NEXTMAP[pos.y][pos.x][dir];
    }
    return (eat);
}

void    backTracking(const t_pos &cur, int curEat=0, int depth=0)
{
    static const int DEPTH_LIMIT = 3;
    static const int dy[] = {-1, 0, 1, 0};
    static const int dx[] = {0, -1, 0, 1};
    static const int dirSize = sizeof(dy) / sizeof(dy[0]);

    if (depth == DEPTH_LIMIT)
    {
        if (maxEat < curEat)
        {
            maxEat = curEat;
            pacMan = cur;
            ate = cmp;
        }
        return ;
    }

    for (int dir = 0; dir < dirSize; ++dir)
    {
        t_pos next = {
            cur.y + dy[dir],
            cur.x + dx[dir]
        };

        if (!inRange(next))
            continue ;

        int &nextVisited = visited[next.y][next.x];
        int nextEat = (nextVisited ? 0 : getNextEat(next));

        ++nextVisited;
        cmp.push_back(next);

        backTracking(
            next,
            curEat + nextEat,
            depth + 1
        );

        --nextVisited;
        cmp.pop_back();
    }
}

void    movePacMan(void)
{
    maxEat = -1;
    t_pos start = pacMan;

    backTracking(start);
    for (const t_pos &pos : ate)
    {
        for (int dir = 0; dir < dirSize; ++dir)
        {
            int &curCnt = NEXTMAP[pos.y][pos.x][dir];

            if (curCnt)
            {
                curCnt = 0;
                deadTime[pos.y][pos.x] = curTime;
            }
        }
    }
}

void    duplicateMonsters(void)
{
    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            for (int dir = 0; dir < dirSize; ++dir)
            {
                NEXTMAP[y][x][dir] += CURMAP[y][x][dir];
                CURMAP[y][x][dir] = 0;
            }
        }
    }
}

int getMonsterCnt(void)
{
    int cnt = 0;

    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            for (int dir = 0; dir < dirSize; ++dir)
            {
                cnt += CURMAP[y][x][dir];
            }
        }
    }
    return (cnt);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int monsterCnt, turn;

    std::cin >> monsterCnt >> turn;
    while (monsterCnt--)
    {
        int dir;
        t_pos pos;

        std::cin >> pos >> dir;
        ++CURMAP[pos.y][pos.x][dir - 1];
    }
    std::cin >> pacMan;

    while (turn--)
    {
        ++curTime;
        nextIdx = curIdx ^ 1;

        moveMonsters();
        movePacMan();
        duplicateMonsters();

        curIdx = nextIdx;
    }

    std::cout << getMonsterCnt() << '\n';
    return 0;
}