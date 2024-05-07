#include <iostream>
#include <climits>

struct t_pos
{
    int y, x;

    inline bool operator<(const t_pos &other) const
    {
        return (this->x < other.x);
    }
};

enum e_space
{
    EMPTY = 0,
    ENEMY
};

const int MAX = 15;
const int ARCHER_CNT = 3;

int ans, firstEnemyCnt;
int map[MAX][MAX];
int originMap[MAX][MAX];
int archerXpos[ARCHER_CNT];
int ySize, xSize, attackDist;

inline int getDist(t_pos a, t_pos b)
{
    return std::abs(a.y - b.y) + std::abs(a.x - b.x);
}

void    killClosestEnemy(int &killCnt, int &enemyCnt)
{
    static const int archerY = ySize;
    static int dist[ARCHER_CNT];
    static t_pos killArr[ARCHER_CNT];

    for (int i = 0; i < ARCHER_CNT; ++i)
    {
        int &curDist = dist[i];
        t_pos &killPos = killArr[i];
        const int &archerX = archerXpos[i];

        curDist = INT_MAX;
        killPos.y = killPos.x = INT_MAX;
        for (int y = 0; y < ySize; ++y)
        {
            for (int x = 0; x < xSize; ++x)
            {
                int &curSpace = map[y][x];

                if (curSpace != ENEMY)
                    continue ;

                int cmpDist = getDist({y, x}, {archerY, archerX});
                if (cmpDist > attackDist)
                    continue ;

                if (cmpDist == curDist)
                {
                    killPos = std::min(killPos, {y, x});
                }
                else if (cmpDist < curDist)
                {
                    curDist = cmpDist;
                    killPos.y = y;
                    killPos.x = x;
                }
            }
        }
    }

    for (int i = 0; i < ARCHER_CNT; ++i)
    {
        int &curDist = dist[i];
        t_pos &killPos = killArr[i];

        if (curDist == INT_MAX)
            continue ;

        int &killSpace = map[killPos.y][killPos.x];

        killCnt += (killSpace == ENEMY);
        enemyCnt -= (killSpace == ENEMY);
        killSpace = EMPTY;
    }
}

void    moveEnemy(int &enemyCnt)
{
    for (int x = 0; x < xSize; ++x)
    {
        enemyCnt -= (map[ySize - 1][x] == ENEMY);
    }

    for (int y = ySize - 1; y >= 1; --y)
    {
        for (int x = 0; x < xSize; ++x)
            map[y][x] = map[y - 1][x];
    }

    for (int x = 0; x < xSize; ++x)
    {
        map[0][x] = EMPTY;
    }
}

void    simulation(void)
{
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
            map[y][x] = originMap[y][x];
    }

    int killCnt = 0;
    int enemyCnt = firstEnemyCnt;
    while (enemyCnt)
    {
        killClosestEnemy(killCnt, enemyCnt);
        moveEnemy(enemyCnt);
    }
    ans = std::max(ans, killCnt);
}

void    back_tracking(int start=0, int depth=0)
{
    if (depth == ARCHER_CNT)
    {
        simulation();
        return ;
    }

    for (int x = start; x < xSize; ++x)
    {
        archerXpos[depth] = x;
        back_tracking(x + 1, depth + 1);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize >> attackDist;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            int &curSpace = originMap[y][x];

            std::cin >> curSpace;
            firstEnemyCnt += (curSpace == ENEMY);
        }
    }

    back_tracking();
    std::cout << ans << '\n';
    return (0);
}
