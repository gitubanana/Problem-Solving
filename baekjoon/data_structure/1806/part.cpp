#include <iostream>
#include <algorithm>
#include <climits>

const int MAX = 100001;

int size;
int ans = INT_MAX;
uint64_t wantSum;
uint64_t prefixSum[MAX];

void    twoPointer(void)
{
    int left = 0;
    int right = 1;

    while (left < right && right <= size)
    {
        uint64_t curSum = prefixSum[right] - prefixSum[left];

        if (curSum >= wantSum)
        {
            ans = std::min(ans, right - left);
            ++left;
        }
        else
        {
            ++right;
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    uint64_t elem;

    std::cin >> size >> wantSum;
    for (int i = 1; i <= size; ++i)
    {
        std::cin >> elem;
        prefixSum[i] = prefixSum[i - 1] + elem;
    }

    twoPointer();
    std::cout << (ans == INT_MAX ? 0 : ans) << '\n';
    return (0);
}
