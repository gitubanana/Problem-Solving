#include <iostream>

const int MAX_SIZE = 1000;

bool occupied[MAX_SIZE + 1];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size, lineCnt;
    int maxGet, maxGetCake = 0;
    int maxWanted, maxWantedCake = 0;

    std::cin >> size >> lineCnt;
    for (int i = 1; i <= lineCnt; ++i)
    {
        int from, to;
        std::cin >> from >> to;

        int wantedCake = to - from;
        if (maxWantedCake < wantedCake)
        {
            maxWantedCake = wantedCake;
            maxWanted = i;
        }

        int getCake = 0;
        for (int cur = from; cur <= to; ++cur)
        {
            if (occupied[cur])
                continue ;

            occupied[cur] = true;
            ++getCake;
        }

        if (maxGetCake < getCake)
        {
            maxGetCake = getCake;
            maxGet = i;
        }
    }

    std::cout << maxWanted << '\n';
    std::cout << maxGet << '\n';
    return (0);
}
