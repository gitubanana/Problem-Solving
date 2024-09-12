#include <iostream>
#include <unordered_set>
#include <unordered_map>

std::unordered_set<std::string> uset;
std::unordered_map<char, int> playerCnt = {
    {'Y', 2},
    {'F', 3},
    {'O', 4}
};

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int requestCnt;
    char type;

    std::cin >> requestCnt >> type;
    while (requestCnt--)
    {
        std::string name;

        std::cin >> name;
        uset.insert(name);
    }

    std::cout << uset.size() / (playerCnt[type] - 1) << '\n';
    return (0);
}
