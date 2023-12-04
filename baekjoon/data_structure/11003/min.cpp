#include <iostream>
#include <deque>
#include <algorithm>
#include <climits>

struct t_data
{
    int data, pos;
};

typedef std::deque<t_data> t_deque;

const int   MAX = 5000000;

int arr[MAX];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int arr_size, cmp_size;

    std::cin >> arr_size >> cmp_size;
    for (int i = 0; i < arr_size; ++i)
        std::cin >> arr[i];

    t_deque deque;
    for (int i = 0; i < arr_size; ++i)
    {
        const int &cur = arr[i];

        if (!deque.empty() && i - cmp_size == deque.front().pos)
            deque.pop_front();
        while (!deque.empty() && deque.back().data > cur)
            deque.pop_back();
        deque.push_back({cur, i});

        std::cout << deque.front().data << ' ';
    }
    std::cout << '\n';

    return (0);
}
