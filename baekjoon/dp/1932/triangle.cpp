#include <iostream>
#include <algorithm>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    int **dp, **triangle;

    std::cin >> size;
    dp = new int*[size];
    triangle = new int*[size];
    for (int y = 0; y < size; ++y)
    {
        int *&curDp = dp[y];
        int *&curTriangle = triangle[y];

        curDp = new int[y + 1];
        curTriangle = new int[y + 1];
        for (int x = 0; x <= y; ++x)
        {
            curDp[x] = 0;
            std::cin >> curTriangle[x];
        }
    }

    dp[0][0] = triangle[0][0];
    for (int curY = 0; curY < size - 1; ++curY)
    {
        int *&curDp = dp[curY];
        int *&nextDp = dp[curY + 1];
        int *&nextTriangle = triangle[curY + 1];

        for (int curX = 0; curX <= curY; ++curX)
        {
            for (const int &nextX: {curX, curX + 1})
            {
                nextDp[nextX] = std::max(nextDp[nextX],
                                         curDp[curX] + nextTriangle[nextX]);
            }
        }
    }

    int *&lastDp = dp[size - 1];
    std::cout << *std::max_element(lastDp, lastDp + size) << '\n';

    for (int y = 0; y < size; ++y)
    {
        delete[] dp[y];
        delete[] triangle[y];
    }
    delete[] dp;
    delete[] triangle;
    return (0);
}
