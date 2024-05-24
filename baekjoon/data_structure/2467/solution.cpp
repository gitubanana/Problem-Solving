#include <iostream>
#include <algorithm>
#include <climits>

const int MAX = 1e6;

int size;
int arr[MAX];

void    twoPointer(void)
{
    int left = 0;
    int right = size - 1;
    int a, b, minAbs = INT_MAX;

    while (left < right)
    {
        int sum = arr[left] + arr[right];
        int cmpAbs = std::abs(sum);

        if (minAbs > cmpAbs)
        {
            minAbs = cmpAbs;
            a = arr[left];
            b = arr[right];
        }

        if (sum == 0)
            break ;
        else if (sum > 0)
            --right;
        else
            ++left;
    }
    std::cout << a << ' ' << b << '\n';
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
    twoPointer();
    return (0);
}
