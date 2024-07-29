#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <queue>

const int MAX_V = 1001;

int vCnt;
int indegree[MAX_V];
std::vector<int> children[MAX_V];
std::string names[MAX_V];
std::vector<int> edges[MAX_V];
std::unordered_map<std::string, int> strToInt;

void    topologicalSort(void)
{
    std::queue<int> q;
    std::vector<int> roots;

    for (int v = 1; v <= vCnt; ++v)
    {
        if (indegree[v] != 0)
            continue ;

        roots.push_back(v);
        q.push(v);
    }

    while (!q.empty())
    {
        const int cur = q.front();
        q.pop();

        for (const int &next : edges[cur])
        {
            --indegree[next];
            if (indegree[next] == 0)
            {
                children[cur].push_back(next);
                q.push(next);
            }
        }
    }

    std::sort(roots.begin(), roots.end());
    std::cout << roots.size() << '\n';
    for (const int &root : roots)
    {
        std::cout << names[root] << ' ';
    }
    std::cout << '\n';

    for (int i = 1; i <= vCnt; ++i)
    {
        std::string &name = names[i];
        std::vector<int> &myChildren = children[strToInt[name]];

        std::sort(myChildren.begin(), myChildren.end());
        std::cout << name << ' ' << myChildren.size() << ' ';
        for (const int &child : myChildren)
        {
            std::cout << names[child] << ' ';
        }
        std::cout << '\n';
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> vCnt;
    for (int v = 1; v <= vCnt; ++v)
    {
        std::cin >> names[v];
    }
    std::sort(names + 1, names + 1 + vCnt);
    for (int v = 1; v <= vCnt; ++v)
    {
        strToInt[names[v]] = v;
    }

    int eCnt;

    std::cin >> eCnt;
    while (eCnt--)
    {
        std::string child, parent;

        std::cin >> child >> parent;
        int &childId = strToInt[child];
        int &parentId = strToInt[parent];

        ++indegree[childId];
        edges[parentId].push_back(childId);
    }

    topologicalSort();
    return (0);
}
