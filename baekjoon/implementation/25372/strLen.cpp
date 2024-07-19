#include <iostream>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    std::string str;
    const char *msg[] = {"no", "yes"};

    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> str;
        std::cout << msg[(6 <= str.size() && str.size() <= 9)] << '\n';
    }
    return (0);
}
