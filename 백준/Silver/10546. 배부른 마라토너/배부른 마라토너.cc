#include <iostream>
#include <unordered_set>

std::unordered_multiset<std::string> uset;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int cnt;
    std::string name;

    std::cin >> cnt;
    for (int i = 0; i < cnt; ++i)
    {
        std::cin >> name;
        uset.insert(name);
    }
    for (int i = 1; i < cnt; ++i)
    {
        std::cin >> name;
        uset.extract(name);
    }

    std::cout << *uset.begin() << '\n';
    return (0);
}
