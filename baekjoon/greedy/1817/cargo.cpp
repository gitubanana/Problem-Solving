#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int max, cnt = 1;
    int *arr, size;

    std::cin >> size >> max;
    arr = new int[size];
    for (int i = 0; i < size; ++i)
        std::cin >> arr[i];

    int i = 1;
    int book_sum = arr[0];
    for (; i < size; ++i)
    {
        int &next = arr[i];
        if (book_sum + next > max)
            ++cnt, book_sum = next;
        else
            book_sum += next;
    }
    if (size == 0)
        cnt = 0;

    std::cout << cnt << '\n';
    return 0;
}
