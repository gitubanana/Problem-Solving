#include <iostream>
#include <set>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int elem;
    int aCnt, bCnt;
    std::set<int> answer;

    std::cin >> aCnt >> bCnt;
    while (aCnt--)
    {
        std::cin >> elem;
        answer.insert(elem);
    }
    while (bCnt--)
    {
        std::cin >> elem;
        answer.erase(elem);
    }

    std::cout << answer.size() << '\n';
    for (const int &cur : answer)
    {
        std::cout << cur << ' ';
    }
    return (0);
}
