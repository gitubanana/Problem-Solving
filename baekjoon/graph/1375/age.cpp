#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <vector>

const int MAX_V = 1'000'001;

int vCnt, id;
bool visited[MAX_V];
std::vector<int> edges[MAX_V];
std::unordered_map<std::string, int> strToInt;

int &getOrMakeId(const std::string &str)
{
    int &strId = strToInt[str];
    if (strId == 0)
    {
        strId = ++id;
    }

    return (strId);
}

bool dfs(int cur, int toFind)
{
    visited[cur] = true;
    if (cur == toFind)
    {
        return (true);
    }

    for (const int &next : edges[cur])
    {
        if (visited[next])
            continue ;

        if (dfs(next, toFind))
        {
            return (true);
        }
    }
    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    while (eCnt--)
    {
        std::string from, to;

        std::cin >> from >> to;
        int &fromId = getOrMakeId(from);
        int &toId = getOrMakeId(to);

        edges[fromId].push_back(toId);
    }

    int qCnt;

    std::cin >> qCnt;
    while (qCnt--)
    {
        std::string from, to;

        std::cin >> from >> to;
        int &fromId = getOrMakeId(from);
        int &toId = getOrMakeId(to);

        if (fromId == toId)
        {
            std::cout << "gg" << ' ';
            continue ;
        }

        memset(visited, false, sizeof(visited));
        if (dfs(fromId, toId))
        {
            std::cout << from << ' ';
            continue ;
        }

        memset(visited, false, sizeof(visited));
        if (dfs(toId, fromId))
        {
            std::cout << to << ' ';
            continue ;
        }

        std::cout << "gg" << ' ';
    }
    std::cout << '\n';
    return (0);
}
