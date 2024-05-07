#include <iostream>
#include <algorithm>
#include <climits>

const int MAX = 100000;

int size;
int a, b;
int add = INT_MAX;
int arr[MAX];

void    twoPointer(void)
{
    std::sort(arr, arr + size);

    int left = 0;
    int right = size - 1;
    while (left < right)
    {
        int cmpAdd = arr[left] + arr[right];
        int absCmp = std::abs(cmpAdd);

        if (add > absCmp)
        {
            add = absCmp;
            a = arr[left];
            b = arr[right];
        }

        if (cmpAdd == 0)
        {
            break ;
        }
        else if (cmpAdd > 0)
        {
            --right;
        }
        else
        {
            ++left;
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    twoPointer();
    std::cout << a << ' ' << b << '\n';
    return (0);
}
