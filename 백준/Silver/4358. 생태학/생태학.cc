#include <iostream>
#include <iomanip>
#include <map>

int main(void)
{
    double totalCnt = 0;
    std::string name;
    std::map<std::string, int> treeCnt;

    while (std::getline(std::cin, name))
    {
        ++treeCnt[name];
        ++totalCnt;
    }

    for (std::pair<const std::string, int> &cur : treeCnt)
    {
        std::cout << cur.first << ' '
                  << std::fixed << std::setprecision(4)
                  << cur.second * 100 / totalCnt << '\n';
    }
    return (0);
}
