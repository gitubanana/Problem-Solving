#include <iostream>
#include <climits>
#include <algorithm>

const int MAX = 300000;

int gemCnt[MAX];
int size, studentCnt;
int minEnvy = INT_MAX;

inline bool isPossible(int maxTaking)
{
    int gaveCnt = 0;

    for (int i = 0; i < size && gaveCnt <= studentCnt; ++i)
    {
        int &curGem = gemCnt[i];

        gaveCnt += (curGem / maxTaking) + (curGem % maxTaking != 0);
    }
    return (gaveCnt <= studentCnt);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> studentCnt >> size;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> gemCnt[i];
    }

    int left = 1;
    int right = *std::max_element(gemCnt, gemCnt + size);
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (isPossible(mid))
        {
            minEnvy = std::min(minEnvy, mid);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    std::cout << minEnvy << '\n';
    return (0);
}
