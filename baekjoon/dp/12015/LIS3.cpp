#include <iostream>
#include <vector>

std::vector<int> lis;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size, num;

    std::cin >> size >> num;
    lis.reserve(size);
    lis.push_back(num);

    while (--size)
    {
        std::cin >> num;

        if (lis.back() < num)
        {
            lis.push_back(num);
        }
        else
        {
            *std::lower_bound(lis.begin(), lis.end(), num) = num;
        }
    }

    std::cout << lis.size() << '\n';
    return (0);
}
