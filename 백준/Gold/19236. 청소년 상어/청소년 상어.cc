#include <iostream>
#include <cstring>

enum e_space
{
    TAGGER = -1,
    EMPTY
};

struct t_pos
{
    int y, x;
    int dir;
};

const int SIZE = 4;
const int MAX_NUM = SIZE * SIZE;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int maxScore;

inline bool isBound(int y, int x)
{
    return ((0 <= y && y < SIZE)
            && (0 <= x && x < SIZE));
}

void    moveThief(int map[SIZE][SIZE],
                  int thiefNum,
                  t_pos thieves[MAX_NUM + 1])
{
    t_pos &cur = thieves[thiefNum];
    int &curSpace = map[cur.y][cur.x];
    if (curSpace != thiefNum)
        return ;

    int dirCnt = dirSize;
    while (dirCnt--)
    {
        int nextY = cur.y + dy[cur.dir];
        int nextX = cur.x + dx[cur.dir];

        if (isBound(nextY, nextX)
            && map[nextY][nextX] != TAGGER)
        {
            int &nextSpace = map[nextY][nextX];
            if (nextSpace != EMPTY)
            {
                t_pos &next = thieves[nextSpace];

                next.y = cur.y, next.x = cur.x;
            }

            cur.y = nextY, cur.x = nextX;
            std::swap(curSpace, nextSpace);
            break ;
        }

        cur.dir = (cur.dir + 1) % dirSize;
    }
}

void    backTracking(int map[SIZE][SIZE],
                     t_pos thieves[MAX_NUM + 1],
                     const t_pos &cur,
                     int curScore)
{
    maxScore = std::max(maxScore, curScore);

    // move Thieves
    for (int num = 1; num <= MAX_NUM; ++num)
    {
        moveThief(map, num, thieves);
    }

    // move Tagger
    t_pos next = {
        cur.y + dy[cur.dir],
        cur.x + dx[cur.dir]
    };

    map[cur.y][cur.x] = EMPTY;
    while (isBound(next.y, next.x))
    {
        int &gotNum = map[next.y][next.x];
        if (gotNum != EMPTY)
        {
            int nextMap[SIZE][SIZE];
            t_pos nextThieves[MAX_NUM + 1];

            memcpy(nextMap, map, sizeof(nextMap));
            memcpy(nextThieves, thieves, sizeof(nextThieves));

            t_pos &got = nextThieves[gotNum];
            int &nextSpace = nextMap[next.y][next.x];
            int plus = nextSpace;

            next.dir = got.dir;
            nextSpace = TAGGER;
            backTracking(nextMap, nextThieves, next, curScore + plus);
        }

        next.y += dy[cur.dir];
        next.x += dx[cur.dir];
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int map[SIZE][SIZE];
    t_pos thieves[MAX_NUM + 1];

    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            int num, dir;

            std::cin >> num >> dir;
            map[y][x] = num;
            thieves[num] = {y, x, dir - 1};
        }
    }

    int &curSpace = map[0][0];
    t_pos cur = {0, 0, thieves[curSpace].dir};
    int firstScore = curSpace;

    curSpace = TAGGER;
    backTracking(map, thieves, cur, firstScore);

    std::cout << maxScore << '\n';
    return 0;
}
