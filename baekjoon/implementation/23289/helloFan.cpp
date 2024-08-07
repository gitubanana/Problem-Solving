#include <iostream>
#include <cstring>
#include <vector>
#define CURTEMP temp[curIdx]
#define NEXTTEMP temp[nextIdx]

enum e_space
{
    EMPTY = 0,
    TO_CHECK = 5
};

struct t_pos
{
    int y, x;
};

struct t_fan : public t_pos
{
    int dir;
};

const int MAX_SIZE = 20;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int curIdx, nextIdx;
int ySize, xSize, wantTemp;
int temp[2][MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
bool isWall[MAX_SIZE][MAX_SIZE][dirSize];
std::vector<t_fan> fans;
std::vector<t_pos> toCheck;

inline bool isBound(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize));
}

inline bool isEnd(void)
{
    for (const t_pos &pos : toCheck)
    {
        if (CURTEMP[pos.y][pos.x] < wantTemp)
        {
            return (false);
        }
    }
    return (true);
}

void    controlTemp(void)
{
    nextIdx = curIdx ^ 1;

    memset(NEXTTEMP, 0, sizeof(NEXTTEMP));
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos cmp = {
                    y + dy[dir],
                    x + dx[dir]
                };

                if (!isBound(cmp) || isWall[y][x][dir])
                    continue ;

                int diff = CURTEMP[y][x] - CURTEMP[cmp.y][cmp.x];
                if (diff < 4)
                    continue ;

                int plus = diff / 4;

                NEXTTEMP[cmp.y][cmp.x] += plus;
                NEXTTEMP[y][x] -= plus;
            }

            NEXTTEMP[y][x] += CURTEMP[y][x];
        }
    }

    curIdx = nextIdx;
}

void    decreaseOutside(void)
{
    for (int y = 0; y < ySize; ++y)
    {
        int xStep = (y == 0 || y == ySize - 1 ? 1 : xSize - 1);

        for (int x = 0; x < xSize; x += xStep)
        {
            int &toDecrease = CURTEMP[y][x];
            if (toDecrease == 0)
                continue ;

            --toDecrease;
        }
    }
}

void    dfs(const t_pos &cur, int fanDir, int plus=5)
{
    static std::vector<int> dirsByFan[dirSize][dirSize - 1] = {
        {{0}, {2, 0}, {3, 0}},
        {{1}, {2, 1}, {3, 1}},
        {{2}, {0, 2}, {1, 2}},
        {{3}, {0, 3}, {1, 3}}
    };

    visited[cur.y][cur.x] = true;
    CURTEMP[cur.y][cur.x] += plus;
    if (plus == 1)
        return ;

    for (std::vector<int> &dirs : dirsByFan[fanDir])
    {
        bool canGo = true;
        t_pos next = cur;

        for (const int &dir : dirs)
        {
            if (!isBound(next) || isWall[next.y][next.x][dir])
            {
                canGo = false;
                break ;
            }

            next.y += dy[dir];
            next.x += dx[dir];
        }

        if (canGo && isBound(next) && !visited[next.y][next.x])
        {
            dfs(next, fanDir, plus - 1);
        }
    }
}

inline void    workFans(void)
{
    for (const t_fan &fan : fans)
    {
        memset(visited, false, sizeof(visited));
        dfs(
            {
                fan.y + dy[fan.dir],
                fan.x + dx[fan.dir]
            },
            fan.dir
        );
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int wallCnt;

    std::cin >> ySize >> xSize >> wantTemp;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            int &space = CURTEMP[y][x];

            std::cin >> space;
            switch (space)
            {
            case EMPTY:
                break;
            case TO_CHECK:
                toCheck.push_back({y, x});
                break;
            default:
                fans.push_back({y, x, space - 1});
                break;
            }

            space = EMPTY;
        }
    }

    std::cin >> wallCnt;
    while (wallCnt--)
    {
        int y, x, t;

        std::cin >> y >> x >> t;
        int dir = (t == 0) * 2;

        --y, --x;
        isWall[y][x][dir] = true;
        isWall[y + dy[dir]][x + dx[dir]][dir ^ 1] = true;
    }

    int eatCnt = 0;
    do
    {
        workFans();
        controlTemp();
        decreaseOutside();
        ++eatCnt;
    } while (!isEnd() && eatCnt <= 100);

    std::cout << eatCnt << '\n';
    return (0);
}
