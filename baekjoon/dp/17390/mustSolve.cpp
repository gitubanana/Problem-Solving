#include <iostream>
#include <algorithm>

const int MAX_SIZE = 300'001;

int size;
int prefixSum[MAX_SIZE];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int qCnt;

    std::cin >> size >> qCnt;
    for (int i = 1; i <= size; ++i)
    {
        std::cin >> prefixSum[i];
    }

    std::sort(prefixSum + 1, prefixSum + 1 + size);
    for (int i = 2; i <= size; ++i)
    {
        prefixSum[i] += prefixSum[i - 1];
    }

    while (qCnt--)
    {
        int L, R;

        std::cin >> L >> R;
        std::cout << prefixSum[R] - prefixSum[L - 1] << '\n';
    }
    return (0);
}
