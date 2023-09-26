#include <iostream>

int main(void)
{
    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int *prefix_sum, size;
    int test_cnt, start, end, sum, tmp;

    std::cin >> size >> test_cnt;
    prefix_sum = new int[size + 1];
    sum = 0;
    for (int i = 1; i <= size; ++i)
    {
        std::cin >> tmp;
        sum += tmp;
        prefix_sum[i] = sum;
    }
    while (test_cnt--)
    {
        std::cin >> start >> end;
        std::cout << prefix_sum[end] - prefix_sum[start - 1] << '\n';
    }
    return (0);
}
