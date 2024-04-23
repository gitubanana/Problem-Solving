#include <iostream>
#include <algorithm>

struct t_land
{
    static const int MAX_TREE_CNT = 1024;
    static const int INIT_NUTRIENT = 5;

    int cnt;
    int nutrient;
    int ages[MAX_TREE_CNT];

    t_land() : cnt(0), nutrient(INIT_NUTRIENT) {}

    inline void    addTree(int age)
    {
        this->ages[this->cnt++] = age;
    }
};

const int MAX = 11;
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size, totalTreeCnt;
int addNutrient[MAX][MAX];
t_land land[MAX][MAX];

inline std::istream &operator>>(std::istream &in, t_land &input)
{
    int treeAge;

    in >> treeAge;
    input.addTree(treeAge);
    return (in);
}

void    springAndSummer(void)
{
    for (int y = 1; y <= size; ++y)
    {
        for (int x = 1; x <= size; ++x)
        {
            t_land &curLand = land[y][x];
            int deadIdx = curLand.cnt;

            std::sort(curLand.ages, curLand.ages + curLand.cnt);
            for (int i = 0; i < curLand.cnt; ++i)
            {
                int &treeAge = curLand.ages[i];

                if (treeAge > curLand.nutrient)
                {
                    deadIdx = i;
                    break ;
                }

                curLand.nutrient -= treeAge;
                ++treeAge;
            }

            totalTreeCnt -= curLand.cnt - deadIdx;
            for (int i = deadIdx; i < curLand.cnt; ++i)
            {
                int &deadAge = curLand.ages[i];

                curLand.nutrient += deadAge / 2;
            }
            curLand.cnt = deadIdx;
        }
    }
}

void    breed(int y, int x)
{
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(1 <= nextY && nextY <= size)
            || !(1 <= nextX && nextX <= size))
            continue;

        t_land &nextLand = land[nextY][nextX];

        nextLand.addTree(1);
        ++totalTreeCnt;
    }
}

void    fall(void)
{
    for (int y = 1; y <= size; ++y)
    {
        for (int x = 1; x <= size; ++x)
        {
            t_land &curLand = land[y][x];

            for (int i = 0; i < curLand.cnt; ++i)
            {
                int &treeAge = curLand.ages[i];

                if (treeAge % 5 == 0)
                    breed(y, x);
            }
        }
    }
}

void    winter(void)
{
    for (int y = 1; y <= size; ++y)
    {
        for (int x = 1; x <= size; ++x)
        {
            t_land &curLand = land[y][x];

            curLand.nutrient += addNutrient[y][x];
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int year;
    int treeY, treeX;

    std::cin >> size >> totalTreeCnt >> year;
    for (int y = 1; y <= size; ++y)
    {
        for (int x = 1; x <= size; ++x)
        {
            std::cin >> addNutrient[y][x];
        }
    }
    for (int i = 0; i < totalTreeCnt; ++i)
    {
        std::cin >> treeY >> treeX >> land[treeY][treeX];
    }

    while (year && totalTreeCnt)
    {
        springAndSummer();
        fall();
        winter();
        --year;
    }

    std::cout << totalTreeCnt << '\n';
    return (0);
}
