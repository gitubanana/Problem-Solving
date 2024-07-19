#include <iostream>
#include <unordered_set>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int num;
    int iter = 0;
    std::unordered_set<int> visited;

    std::cin >> num;
    while (visited.find(num) == visited.end())
    {
        int secThird = (num / 100 % 10) * 10 + (num / 10 % 10);

        visited.insert(num);
        num = secThird * secThird;
        ++iter;
    }

    std::cout << iter << '\n';
    return (0);
}
