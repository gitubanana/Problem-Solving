#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

struct t_coord
{
    int x;
    int idx;

    inline bool operator<(const struct t_coord &other) const
    {
        return (this->x < other.x);
    }
};

int main(void)
{
    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int size;
    int *arr;
    std::set<int>   _set;

    std::cin >> size;
    arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
        _set.insert(arr[i]);
    }

    std::map<int, int>  ans;
    std::set<int, int>::iterator    it = _set.begin();
    for (int compressed_x = 0; it != _set.end(); ++it, ++compressed_x)
    {
        ans[*it] = compressed_x;
    }

    for (int i = 0; i < size; ++i)
    {
        std::cout << ans[arr[i]] << ' ';
    }
    std::cout << '\n';
    return (0);
}
