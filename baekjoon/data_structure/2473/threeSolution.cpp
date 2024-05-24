#include <iostream>
#include <algorithm>
#include <climits>

const int MAX_SIZE = 5000;

int size;
int64_t arr[MAX_SIZE];

int binarySearch(int left, int right, int64_t plus)
{
    int retIdx;
    int64_t minAdd = LONG_LONG_MAX;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int64_t sum = arr[mid] + plus;
        int64_t cmpAdd = std::abs(sum);

        if (minAdd > cmpAdd)
        {
            minAdd = cmpAdd;
            retIdx = mid;
        }

        if (sum == 0)
            break ;

        if (sum > 0)
            --right;
        else
            ++left;
    }
    return (retIdx);
}

void    threePointer(void)
{
    int64_t ans[3];
    int64_t minAdd = LONG_LONG_MAX;

    for (int i = 0; i < size; ++i)
    {
        int left = 0;
        int right = size - 1;
        while (left < right)
        {
            if (left == i)
            {
                ++left;
                continue ;
            }
            else if (right == i)
            {
                --right;
                continue ;
            }

            int64_t sum = arr[i] + arr[left] + arr[right];
            int64_t absAdd = std::abs(sum);

            if (minAdd > absAdd)
            {
                minAdd = absAdd;
                ans[0] = arr[left];
                ans[1] = arr[i];
                ans[2] = arr[right];
            }

            if (sum == 0)
            {
                i = size;
                break ;
            }

            if (sum > 0)
                --right;
            else
                ++left;
        }
    }

    std::sort(ans, ans + 3);
    for (int i = 0; i < 3; ++i)
    {
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    std::sort(arr, arr + size);
    threePointer();
    return (0);
}
