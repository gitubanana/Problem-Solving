#include <iostream>

// 뒤에서부터 가장 큰 거를 갱신해주면서
//  가장 큰 거에 올인!

const int MAX_SIZE = 1e6;

int size;
int cost[MAX_SIZE];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        std::cin >> size;
        for (int i = 0; i < size; ++i)
        {
            std::cin >> cost[i];
        }

        int64_t totalEarn = 0;
        int max = cost[size - 1];
        for (int i = size - 2; i >= 0; --i)
        {
            int &curCost = cost[i];

            if (max < curCost)
            {
                max = curCost;
            }
            else
            {
                totalEarn += (max - curCost);
            }
        }

        std::cout << '#' << t << ' ' << totalEarn << '\n';
    }
    return (0);
}
