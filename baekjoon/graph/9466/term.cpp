#include <iostream>

const int MAX_SIZE = 100000;
const int SELF = 0;
const int NO_CYCLE = -2;

int size, noTeam, cycleStart;
int mate[MAX_SIZE + 1];

bool findTeam(int cur)
{
    int next = mate[cur];
    if (next == SELF)
    {
        return (false);
    }

    if (next == cur)
    {
        cycleStart = cur;
        return (true);
    }

    mate[cur] = cur;
    bool madeTeam = findTeam(next);
    mate[cur] = SELF;

    if (cycleStart == cur)
    {
        return (false);
    }

    noTeam += !madeTeam;
    return (madeTeam);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> size;
        for (int v = 1; v <= size; ++v)
        {
            int &curMate = mate[v];

            std::cin >> curMate;
            if (curMate == v)
                curMate = SELF;
        }

        noTeam = 0;
        for (int v = 1; v <= size; ++v)
        {
            int &curMate = mate[v];
            if (curMate == SELF)
                continue ;

            cycleStart = NO_CYCLE;
            findTeam(v);
        }
        std::cout << noTeam << '\n';
    }
    return (0);
}
