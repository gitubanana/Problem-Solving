#include <iostream>
#include <algorithm>

typedef unsigned long long ull;

ull max;

void    find_max_rectangle(ull *arr, int left, int right)
{
    if (left == right)
    {
        max = std::max(max, arr[left]);
        return ;
    }

    int mid = (left + right) / 2;

    find_max_rectangle(arr, left, mid);
    find_max_rectangle(arr, mid + 1, right);

    int l_idx = mid;
    int r_idx = mid;
    ull scale = arr[mid];

    while (l_idx > left || r_idx < right)
    {
        int next_l = l_idx - 1;
        int next_r = r_idx + 1;

        if (l_idx == left)
            scale = std::min(scale, arr[next_r]), ++r_idx;
        else if (r_idx == right)
            scale = std::min(scale, arr[next_l]), --l_idx;
        else if (arr[next_l] > arr[next_r])
        {
            scale = std::min(scale, arr[next_l]);
            --l_idx;
        }
        else
        {
            scale = std::min(scale, arr[next_r]);
            ++r_idx;
        }
        max = std::max(max, scale * (r_idx - l_idx + 1));
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    ull *arr;
    int size;

    std::cin >> size;

    arr = new ull[size];
    for (int i = 0; i < size; ++i)
        std::cin >> arr[i];

    max = 0;
    find_max_rectangle(arr, 0, size - 1);
    std::cout << max << '\n';

    delete[] arr;
    return (0);
}
