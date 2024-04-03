#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 20002;

bool isNotPrime[MAX];
std::vector<int> primeNums;

inline void    printGoldBach(int n)
{
    int left = 0;
    int right = std::upper_bound(primeNums.begin(), primeNums.end(), n) - primeNums.begin();
    int leftNum, rightNum;

    while (left <= right)
    {
        int sum = primeNums[left] + primeNums[right];

        if (sum == n)
        {
            leftNum = primeNums[left];
            rightNum = primeNums[right];
            ++left;
        }
        else if (sum < n)
        {
            ++left;
        }
        else
        {
            --right;
        }
    }
    std::cout << leftNum << ' ' << rightNum << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int n;
    int testCnt;

    for (int i = 2; i < MAX; ++i)
    {
        if (isNotPrime[i])
            continue ;

        primeNums.push_back(i);
        for (int num = i + i; num < MAX; num += i)
        {
            isNotPrime[num] = true;
        }
    }

    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> n;
        printGoldBach(n);
    }
    return (0);
}
