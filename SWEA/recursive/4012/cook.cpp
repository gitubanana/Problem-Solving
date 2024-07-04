#include <iostream>
#include <climits>

const int MAX_SIZE = 16;

int size, halfSize, minDiff;
bool chosen[MAX_SIZE];
int synergy[MAX_SIZE][MAX_SIZE];

void    findMinDiff(int start=0, int depth=0)
{
    if (depth == halfSize)
    {
        int energy[2] = {0, 0};

        for (int y = 0; y < size; ++y)
        {
            for (int x = 0; x < size; ++x)
            {
                if (chosen[y] != chosen[x])
                    continue ;

                energy[chosen[y]] += synergy[y][x];
            }
        }

        minDiff = std::min(
            minDiff,
            std::abs(energy[0] - energy[1])
        );
        return ;
    }

    for (int next = start; next < size; ++next)
    {
        chosen[next] = true;
        findMinDiff(next + 1, depth + 1);
        chosen[next] = false;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        std::cin >> size;
        for (int y = 0; y < size; ++y)
        {
            for (int x = 0; x < size; ++x)
            {
                std::cin >> synergy[y][x];
            }
        }

        halfSize = size / 2;
        minDiff = INT_MAX;
        findMinDiff();
        std::cout << '#' << t << ' ' << minDiff << '\n';
    }
    return (0);
}
