#include <iostream>
#include <algorithm>

struct t_elem
{
    int num;
    int index;

    inline bool operator<(const struct t_elem &other) const
    {
        return (this->num < other.num);
    }
};

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    t_elem *arr;
    int     *to_print;

    std::cin >> size;
    arr = new t_elem[size];
    to_print = new int[size];
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i].num;
        arr[i].index = i;
    }

    std::stable_sort(arr, arr + size);

    for (int i = 0; i < size; ++i)
        to_print[arr[i].index] = i;

    for (int i = 0; i < size; ++i)
        std::cout << to_print[i] << ' ';
    std::cout << '\n';

    delete[] arr;
    delete[] to_print;
    return (0);
}
