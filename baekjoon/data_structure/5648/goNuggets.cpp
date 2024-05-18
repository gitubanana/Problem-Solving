#include <iostream>
#include <algorithm>

const int MAX = 1e6;

int size;
int64_t arr[MAX];

int64_t reverseNum(std::string &num)
{
    int64_t ret = 0;

    for (int i = num.size() - 1; i >= 0; --i)
    {
        ret = ret * 10 + (num[i] - '0');
    }
    return (ret);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::string num;

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> num;

        arr[i] = reverseNum(num);
    }

    std::sort(arr, arr + size);
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << '\n';
    }
    return (0);
}
