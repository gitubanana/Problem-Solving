#include <iostream>
#include <climits>

enum e_space
{
    SHARK = -1,
    EMPTY
};

struct t_pos
{
    int y, x;
    int dir;
    bool isEaten;

    t_pos() : isEaten(false) {}
};

const int MAX = 4;
const int FISH_CNT = MAX * MAX;
const int DIR_CNT = 8;
const char *dirMsg[] = {"위", "위+왼", "왼", "아래+왼", "아래", "아래+오른", "오른", "위+오른"};

int max = INT_MIN;
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

int map[MAX][MAX];
t_pos fishes[FISH_CNT + 1];
t_pos shark;

void    moveFishes(int curMap[MAX][MAX], t_pos fishes[FISH_CNT + 1])
{
    for (int i = 1; i <= FISH_CNT; ++i)
    {
        t_pos &curFish = fishes[i];

        if (curFish.isEaten)
            continue ;

        for (int i = 0; i < DIR_CNT;
            ++i, curFish.dir = (curFish.dir + 1) % DIR_CNT)
        {
            int nextY = curFish.y + dy[curFish.dir];
            int nextX = curFish.x + dx[curFish.dir];

            if (!(0 <= nextY && nextY < MAX)
                || !(0 <= nextX && nextX < MAX)
                || curMap[nextY][nextX] == SHARK)
                continue ;

            int toSwap = curMap[nextY][nextX];

            std::swap(curMap[curFish.y][curFish.x], curMap[nextY][nextX]);
            if (toSwap == EMPTY)
            {
                curFish.y = nextY;
                curFish.x = nextX;
            }
            else
            {
                std::swap(curFish.y, fishes[toSwap].y);
                std::swap(curFish.x, fishes[toSwap].x);
            }
            break ;
        }
    }
}

void    back_tracking(int shouldCopy[MAX][MAX], t_pos fishes[FISH_CNT + 1], int ate)
{
    int curMap[MAX][MAX];
    t_pos curFishes[FISH_CNT + 1];
    for (int y = 0; y < MAX; ++y)
    {
        for (int x = 0; x < MAX; ++x)
        {
            curMap[y][x] = shouldCopy[y][x];
        }
    }
    for (int i = 1; i <= FISH_CNT; ++i)
        curFishes[i] = fishes[i];
 
    max = std::max(max, ate);

    // fish map copy 필요
    moveFishes(curMap, curFishes);

    // moveShark
    t_pos originShark = shark;
    int nextY = originShark.y + dy[originShark.dir];
    int nextX = originShark.x + dx[originShark.dir];
    while (true)
    {
        if (!(0 <= nextY && nextY < MAX)
            || !(0 <= nextX && nextX < MAX))
            break ;

        int nextSpace = curMap[nextY][nextX];
        if (nextSpace != EMPTY)
        {
            int go[MAX][MAX];
            t_pos goFishes[FISH_CNT + 1];

            for (int y = 0; y < MAX; ++y)
            {
                for (int x = 0; x < MAX; ++x)
                {
                    go[y][x] = curMap[y][x];
                }
            }
            for (int i = 1; i <= FISH_CNT; ++i)
            {
                goFishes[i] = curFishes[i];
            }

            shark = goFishes[nextSpace];
            go[originShark.y][originShark.x] = EMPTY;
            goFishes[nextSpace].isEaten = true;
            go[nextY][nextX] = SHARK;

            back_tracking(go, goFishes, ate + nextSpace);

            shark = originShark;
        }

        nextY += dy[originShark.dir];
        nextX += dx[originShark.dir];
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int num;
    for (int y = 0; y < MAX; ++y)
    {
        for (int x = 0; x < MAX; ++x)
        {
            std::cin >> num >> fishes[num].dir;
            --fishes[num].dir;
            fishes[num].y = y;
            fishes[num].x = x;
            map[y][x] = num;
        }
    }

    int ate = map[0][0];
    int &curSpace = map[0][0];

    shark = fishes[curSpace];
    fishes[curSpace].isEaten = true;
    curSpace = SHARK;
    back_tracking(map, fishes, ate);

    std::cout << max << '\n';
    return (0);
}
