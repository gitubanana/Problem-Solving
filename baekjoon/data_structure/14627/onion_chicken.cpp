#include <iostream>

uint64_t *arr, size;

uint64_t count_chicken(uint64_t onionLen)
{
    uint64_t ret = 0;

    for (uint64_t i = 0; i < size; ++i)
        ret += arr[i] / onionLen;
    return (ret);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    uint64_t chickenCnt;
    uint64_t sum = 0;

    std::cin >> size >> chickenCnt;
    arr = new uint64_t[size];
    for (uint64_t i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
        sum += arr[i];
    }

    uint64_t ans = -1;
    uint64_t left = 1;
    uint64_t right = sum / chickenCnt;
    while (left <= right)
    {
        uint64_t mid = (left + right) / 2;
        uint64_t availableChicken = count_chicken(mid);
        if (availableChicken >= chickenCnt)
        {
            ans = std::min(ans, sum - (mid * chickenCnt));
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    std::cout << ans << '\n';
    delete[] arr;
    return (0);
}
