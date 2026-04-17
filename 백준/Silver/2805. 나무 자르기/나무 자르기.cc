#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

typedef std::vector<int64_t>    t_vec;

int64_t ans;

int64_t cut_height(t_vec arr, int64_t size, int64_t machine_h)
{
    int get;
    int64_t ret = 0;

    for (int i = 0; i < size; ++i)
    {
        get = arr[i] - machine_h;
        if (get > 0)
            ret += get;
    }
    return (ret);
}

void    parametric_search(t_vec arr, int64_t size, int64_t goal)
{
    int64_t left, right, mid;

    left = *(std::max_element(arr.begin(), arr.end()));
    right = 0;
    while (left >= right)
    {
        mid = (left + right) / 2;
        if (cut_height(arr, size, mid) >= goal)
        {
            ans = std::max(ans, mid);
            right = mid + 1;
        }
        else
            left = mid - 1;
    }
}

int main(void)
{
    t_vec arr;
    int64_t size;
    int64_t goal;

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> size >> goal;
    for (int i = 0, tmp; i < size; ++i)
    {
        std::cin >> tmp;
        arr.push_back(tmp);
    }
    parametric_search(arr, size, goal);
    std::cout << ans << '\n';
    return (0);
}