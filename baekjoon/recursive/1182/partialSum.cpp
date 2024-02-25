#include <iostream>

const int MAX = 20;

int arr[MAX];
int size, goal;
int limit, cnt;

void    back_tracking(int start, int curSum, int depth)
{
    if (depth == limit)
    {
        cnt += (curSum == goal);
        return ;
    }

    for (int i = start; i < size; ++i)
    {
        back_tracking(i + 1, curSum + arr[i], depth + 1);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size >> goal;
    for (int i = 0; i < size; ++i)
        std::cin >> arr[i];

    for (int i = 1; i <= size; ++i)
    {
        limit = i;
        back_tracking(0, 0, 0);
    }

    std::cout << cnt << '\n';
    return (0);
}
