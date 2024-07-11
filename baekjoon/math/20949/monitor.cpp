#include <iostream>
#include <algorithm>
#include <vector>

struct t_monitor
{
    int num;
    int idx;

    inline bool operator<(const t_monitor &other) const
    {
        if (this->num == other.num)
            return (this->idx < other.idx);

        return (this->num > other.num);
    }
};

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    std::vector<t_monitor> arr;

    std::cin >> size;
    for (int i = 1; i <= size; ++i)
    {
        int width, height;

        std::cin >> width >> height;
        arr.push_back({width * width + height * height, i});
    }

    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i].idx << '\n';
    }
    return (0);
}
