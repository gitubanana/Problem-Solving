#include <iostream>

const int MAX_SIZE = 9;

int ans, limit;
int arr[MAX_SIZE];

void    backTracking(int sum=0, int depth=0)
{
    if (depth == limit)
    {
        ans += (sum % 3 == 0);
        return ;
    }

    for (int num = (depth == 0); num <= 2; ++num)
    {
        arr[depth] = num;
        backTracking(sum + num, depth + 1);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> limit;

    backTracking();
    std::cout << ans << '\n';
    return (0);
}
