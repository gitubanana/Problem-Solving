#include <iostream>
#include <algorithm>
#include <climits>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int tmp;
    int arr_size, k;

    std::cin >> arr_size >> k;

    int *psum = new int[arr_size];
    std::cin >> psum[0];
    for (int i = 1; i < arr_size; ++i)
    {
        std::cin >> tmp;
        psum[i] = psum[i - 1] + tmp;
    }

    int max = psum[k - 1];
    for (int i = 0; i < arr_size - k; ++i)
    {
        max = std::max(max, psum[k + i] - psum[i]);
    }
    std::cout << max << '\n';
    
    delete[] psum;
    return 0;
}
