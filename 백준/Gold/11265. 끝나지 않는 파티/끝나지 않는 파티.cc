#include <iostream>

const int MAX_V = 501;

int vCnt;
int dists[MAX_V][MAX_V];

void    floyd(void)
{
    for (int mid = 1; mid <= vCnt; ++mid)
    {
        for (int from = 1; from <= vCnt; ++from)
        {
            for (int to = 1; to <= vCnt; ++to)
            {
                dists[from][to] = std::min(
                    dists[from][to],
                    dists[from][mid] + dists[mid][to]
                );
            }
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int qCnt;
    const char *msg[] = {"Stay here", "Enjoy other party"};

    std::cin >> vCnt >> qCnt;
    for (int from = 1; from <= vCnt; ++from)
    {
        for (int to = 1; to <= vCnt; ++to)
        {
            std::cin >> dists[from][to];
        }
    }

    floyd();

    while (qCnt--)
    {
        int from, to, timeLimit;

        std::cin >> from >> to >> timeLimit;
        std::cout << msg[dists[from][to] <= timeLimit] << '\n';
    }
    return (0);
}
