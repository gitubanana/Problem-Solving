#include <iostream>
#include <cstring>
#define CURMAP map[curIdx]
#define NEXTMAP map[nextIdx]

enum e_space
{
    EMPTY = 0
};

struct t_herd
{
    int y, x;
    int dir;
    int animalCnt;
    int toAdd;
};

const int MAX_SIZE = 100;
const int MAX_HERD_CNT = 1000;
const int dy[] = {0, -1, 1, 0, 0};
const int dx[] = {0, 0, 0, -1, 1};

int size;
int curIdx, nextIdx;
int map[2][MAX_SIZE][MAX_SIZE];
int herdCnt;
t_herd herds[MAX_HERD_CNT + 1];

inline std::istream &operator>>(std::istream &in, t_herd &input)
{
    std::cin >> input.y >> input.x >> input.animalCnt >> input.dir;
    return (in);
}

inline bool isHurting(int y, int x)
{
    return (y == 0 || y == size - 1
            || x == 0 || x == size - 1);
}

inline int getOpposite(int dir)
{
    static const int opposite[] = {0, 2, 1, 4, 3};
    return (opposite[dir]);
}

void    moveHerd(int herdNum)
{
    t_herd &toMove = herds[herdNum];
    int nextY = toMove.y + dy[toMove.dir]; 
    int nextX = toMove.x + dx[toMove.dir];
    int &nextSpace = NEXTMAP[nextY][nextX];

    CURMAP[toMove.y][toMove.x] = EMPTY;
    toMove.y = nextY;
    toMove.x = nextX;

    if (isHurting(nextY, nextX))
    {
        toMove.dir = getOpposite(toMove.dir);
        toMove.animalCnt /= 2;
    }
    else if (nextSpace != EMPTY)
    {
        t_herd &opponent = herds[nextSpace];

        if (toMove.animalCnt > opponent.animalCnt)
        {
            toMove.toAdd += opponent.animalCnt + opponent.toAdd;
            opponent.animalCnt = opponent.toAdd = 0;
            nextSpace = herdNum;
        }
        else
        {
            opponent.toAdd += toMove.animalCnt + toMove.toAdd;
            toMove.animalCnt = toMove.toAdd = 0;
        }
    }
    else
    {
        nextSpace = herdNum;
    }
}

inline int countAnimal(void)
{
    int cnt = 0;

    for (int i = 1; i <= herdCnt; ++i)
    {
        cnt += herds[i].animalCnt;
    }
    return (cnt);
}

void    clearCurMap(void)
{    
    for (int i = 1; i <= herdCnt; ++i)
    {
        t_herd &cur = herds[i];

        CURMAP[cur.y][cur.x] = EMPTY;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    int moveTime;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        std::cin >> size >> moveTime >> herdCnt;

        for (int i = 1; i <= herdCnt; ++i)
        {
            t_herd &cur = herds[i];

            std::cin >> cur;
            CURMAP[cur.y][cur.x] = i;
            cur.toAdd = 0;
        }

        while (moveTime--)
        {
            nextIdx = (curIdx + 1) % 2;
            for (int i = 1; i <= herdCnt; ++i)
            {
                if (herds[i].animalCnt == 0)
                    continue ;

                moveHerd(i);
            }

            for (int i = 1; i <= herdCnt; ++i)
            {
                t_herd &cur = herds[i];

                cur.animalCnt += cur.toAdd;
                cur.toAdd = 0;
            }
            curIdx = nextIdx;
        }

        std::cout << "#" << t << ' ' << countAnimal() << '\n';
        clearCurMap();
    }
    return (0);
}
