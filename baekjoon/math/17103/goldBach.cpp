#include <iostream>

const int MAX = 1000001;

bool isNotPrime[MAX];

int    countPartition(int n)
{
    int cnt = 0;
    int halfN = n / 2;

    for (int i = 2; i <= halfN; ++i)
    {
        cnt += (!isNotPrime[i] && !isNotPrime[n - i]);
    }
    return cnt;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i < MAX; ++i)
    {
        if (isNotPrime[i])
            continue ;

        for (int num = i + i; num < MAX; num += i)
        {
            isNotPrime[num] = true;
        }
    }

    int n;
    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> n;
        std::cout << countPartition(n) << '\n';
    }
    return (0);
}
