#include <iostream>
#include <algorithm>
#include <unordered_set>

const int MAX = 8;

int arr[MAX];
int toPrint[MAX];
bool visited[MAX];
int size, limit;

void    back_tracking(int start=0, int depth=0)
{
    if (depth == limit)
    {
        for (int i = 0; i < limit; ++i)
        {
            std::cout << toPrint[i] << ' ';
        }
        std::cout << '\n';
        return ;
    }

    for (int i = start; i < size; )
    {
        int cur = arr[i];

        toPrint[depth] = arr[i];
        back_tracking(++i, depth + 1);
        while (arr[i] == cur)
            ++i;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size >> limit;
    for (int i = 0; i < size; ++i)
        std::cin >> arr[i];

    std::sort(arr, arr + size);
    back_tracking();
    return (0);
}
