#include <iostream>
#include <algorithm>

struct t_time
{
    int arrived;
    int test;

    inline bool operator<(const t_time &other) const
    {
        return (arrived < other.arrived);
    }
};

std::istream &operator>>(std::istream &in, t_time &time_)
{
    in >> time_.arrived >> time_.test;
    return (in);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    t_time *arr;

    std::cin >> size;
    arr = new t_time[size];
    for (int i = 0; i < size; ++i)
        std::cin >> arr[i];

    std::sort(arr, arr + size);

    int curTime = 0;
    for (int i = 0; i < size; ++i)
    {
        curTime = std::max(curTime, arr[i].arrived);
        curTime += arr[i].test;
    }

    std::cout << curTime << '\n';
    delete[] arr;
    return (0);
}
