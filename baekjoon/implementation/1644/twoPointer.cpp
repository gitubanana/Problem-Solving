#include <iostream>
#include <vector>

const int MAX = 4000001;

int ans;
int goal;
bool isNotPrime[MAX];
std::vector<int> primeNumbers;

void twoPointer(void)
{
    int start = 0;
    int end = 1;
    int sum = primeNumbers[0];

    while (start < end && end <= primeNumbers.size())
    {
        if (sum < goal)
        {
            sum += primeNumbers[end++];
        }
        else
        {
            ans += (sum == goal);
            sum -= primeNumbers[start++];
        }
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> goal;

    for (int i = 2; i <= goal; ++i)
    {
        if (isNotPrime[i])
            continue ;

        primeNumbers.push_back(i);

        int toDelete = i + i;
        while (toDelete <= goal)
        {
            isNotPrime[toDelete] = true;
            toDelete += i;
        }
    }

    if (primeNumbers.size() >= 1)
        twoPointer();

    std::cout << ans << '\n';
    return 0;
}

// 2, 3, 5, 7, 11, 13, ...
