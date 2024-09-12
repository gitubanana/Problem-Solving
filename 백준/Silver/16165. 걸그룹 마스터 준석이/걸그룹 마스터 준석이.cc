#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

std::unordered_map<std::string, std::vector<std::string>> nameByGroup;
std::unordered_map<std::string, std::string> groupByName;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::string group, name;
    int groupCnt, qCnt, nameCnt;

    std::cin >> groupCnt >> qCnt;
    while (groupCnt--)
    {
        std::cin >> group >> nameCnt;
        while (nameCnt--)
        {
            std::cin >> name;
            nameByGroup[group].push_back(name);
            groupByName[name] = group;
        }

        std::sort(nameByGroup[group].begin(), nameByGroup[group].end());
    }

    int type;
    while (qCnt--)
    {
        std::cin >> name >> type;
        switch (type)
        {
        case 0:
            for (const std::string &m : nameByGroup[name])
            {
                std::cout << m << '\n';
            }
            break;
        case 1:
            std::cout << groupByName[name] << '\n';
            break;
        }
    }
    return (0);
}