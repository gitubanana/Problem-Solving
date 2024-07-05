#include <iostream>
#include <cmath>

struct t_roller
{
    int y, x;
    int radius;
};

const int MAX_SIZE = 1080;

int size;
bool visited[MAX_SIZE];
t_roller rollers[MAX_SIZE];

inline int getDist(t_roller &a, t_roller &b)
{
    return std::sqrt(std::pow(std::abs(a.y - b.y), 2)
                    + std::pow(std::abs(a.x - b.x), 2));
}

void    findNextRoller(int &curIdx)
{
    t_roller &cur = rollers[curIdx];

    for (int nextIdx = 0; nextIdx < size; ++nextIdx)
    {
        t_roller &next = rollers[nextIdx];

        if (visited[nextIdx])
            continue ;

        if (getDist(cur, next) == cur.radius + next.radius)
        {
            visited[nextIdx] = true;
            curIdx = nextIdx;
            return ;
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int curIdx;

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        t_roller &cur = rollers[i];

        std::cin >> cur.y >> cur.x >> cur.radius;
        if (cur.y == 0 && cur.x == 0)
        {
            visited[i] = true;
            curIdx = i;
        }
    }

    int checkCnt = 1;
    while (checkCnt < size)
    {
        findNextRoller(curIdx);
        ++checkCnt;
    }

    std::cout << rollers[curIdx].y << ' ' << rollers[curIdx].x << '\n';
    return (0);
}
