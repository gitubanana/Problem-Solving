#include <iostream>
#include <climits>
#include <vector>
#include <cstring>
#include <unordered_set>

const int MAX = 11;

int ans = INT_MAX;
int vCnt, sum;
int population[MAX];
bool visited[MAX];
std::unordered_set<int> A;
std::unordered_set<int> B;
std::vector<int> edges[MAX];

void    dfs(int cur, std::unordered_set<int> &linkCheck)
{
    visited[cur] = true;
    for (const int &next : edges[cur])
    {
        if (visited[next]
            || linkCheck.find(next) == linkCheck.end())
            continue;

        dfs(next, linkCheck);
    }
}

bool isLinked(std::unordered_set<int> &linkCheck)
{
    if (linkCheck.empty())
        return (false);

    dfs(*linkCheck.begin(), linkCheck);

    bool isOk = true;
    for (const int &toCheck : linkCheck)
    {
        if (!visited[toCheck])
        {
            isOk = false;
        }
        else
        {
            visited[toCheck] = false;
        }
    }
    return (isOk);
}

void    gerryMandering(int cur, int curSum=0)
{
    if (cur == vCnt + 1)
    {
        if (isLinked(A) && isLinked(B))
        {
            ans = std::min(ans, std::abs(curSum - (sum - curSum)));
        }
        return ;
    }

    int next = cur + 1;

    gerryMandering(next, curSum);

    A.erase(cur);
    B.insert(cur);
    gerryMandering(next, curSum + population[cur]);

    A.insert(cur);
    B.erase(cur);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int to, eCnt;

    std::cin >> vCnt;
    for (int v = 1; v <= vCnt; ++v)
    {
        int &input = population[v];

        std::cin >> input;
        sum += input;
        A.insert(v);
    }
    for (int from = 1; from <= vCnt; ++from)
    {
        std::cin >> eCnt;
        while (eCnt--)
        {
            std::cin >> to;
            edges[from].push_back(to);
        }
    }

    gerryMandering(1);
    std::cout << (ans == INT_MAX ? -1 : ans) << std::endl;
    return (0);
}
