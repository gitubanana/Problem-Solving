#include <iostream>
#include <climits>

const int MAX_SIZE = 20;

int size;
int ans = INT_MAX;
bool isDay[MAX_SIZE];
int intensity[MAX_SIZE][MAX_SIZE];

void    backTracking(int start=0, int depth=0)
{
    static const int depthLimit = size / 2;

    if (depth == depthLimit)
    {
        int sum[2] = {0, 0};

        for (int y = 0; y < size; ++y)
        {
            for (int x = 0; x < size; ++x)
            {
                if (isDay[y] == isDay[x])
                {
                    sum[isDay[y]]
                        += intensity[y][x];
                }
            }
        }

        ans = std::min(ans, std::abs(sum[0] - sum[1]));
        return ;
    }

    for (int i = start; i < size; ++i)
    {
        isDay[i] = true;
        backTracking(i + 1, depth + 1);
        isDay[i] = false;
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> intensity[y][x];
        }
    }

    backTracking();
    std::cout << ans << '\n';
    return 0;
}