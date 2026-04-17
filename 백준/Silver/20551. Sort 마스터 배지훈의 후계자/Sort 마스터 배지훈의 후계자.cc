#include <iostream>
#include <vector>
#include <algorithm>

int binary_search(std::vector<int> &_vec, int to_find)
{
    int mid;
    int idx;
    int left = 0, right = _vec.size() - 1;

    idx = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (_vec[mid] == to_find)
        {
            idx = mid;
            right = mid - 1;
        }
        else if (_vec[mid] > to_find)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return (idx);
}

int main()
{
    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int size, quest_cnt, num;
    std::vector<int>    _vec;

    std::cin >> size >> quest_cnt;
    while (size--)
    {
        std::cin >> num;
        _vec.push_back(num);
    }
    std::sort(_vec.begin(), _vec.end());

    while (quest_cnt--)
    {
        std::cin >> num;
        std::cout << binary_search(_vec, num) << '\n';
    }

    return 0;
}
