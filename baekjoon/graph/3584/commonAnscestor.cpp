#include <iostream>
#include <queue>
#include <unordered_set>
#include <cstring>

const int MAX = 10001;

int parents[MAX];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        int vCnt;
        int parent, child;

        std::cin >> vCnt;
        for (int i = 1; i < vCnt; ++i)
        {
            std::cin >> parent >> child;
            parents[child] = parent;
        }

        int a, b;
        std::queue<int> q;
        std::unordered_set<int> visited;

        std::cin >> a >> b;
        q.push(a), q.push(b);
        visited.insert(a), visited.insert(b);

        while (!q.empty())
        {
            int &next = parents[q.front()];

            if (visited.find(next) != visited.end())
            {
                std::cout << next << '\n';
                break ;
            }
            if (next != 0)
            {
                visited.insert(next);
                q.push(next);
            }
            q.pop();
        }

        memset(parents, 0, sizeof(parents));
    }
    return (0);
}
