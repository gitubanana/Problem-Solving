#include <iostream>
#include <algorithm>

const int MAX = 7;

int arr[MAX];
int toPrint[MAX];
bool visited[MAX];
int size, limit;

void    back_tracking(int depth=0)
{
    if (depth == limit)
    {
        for (int i = 0; i < limit; ++i)
            std::cout << toPrint[i] << ' ';
        std::cout << '\n';
        return ;
    }

    for (int i = 0; i < size; )
    {
        int &cur = arr[i];

        toPrint[depth] = cur;
        back_tracking(depth + 1);

        while (arr[++i] == cur)
            ;
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
