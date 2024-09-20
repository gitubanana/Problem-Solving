#include <iostream>
#include <vector>

const int MAX_V = 500'001;
const int ROOT = 1;

int vCnt;
int totalMove;
std::vector<int> edges[MAX_V];

void    dfs(int cur=ROOT, int prev=0, int depth=0)
{
    bool isLeaf = true;
    std::vector<int> &curEdges = edges[cur];

    for (const int &next : curEdges)
    {
        if (next == prev)
            continue ;

        isLeaf = false;
        dfs(next, cur, depth + 1);
    }

    totalMove += depth * isLeaf;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int from, to;
    const char *msg[] = {"No", "Yes"};

    std::cin >> vCnt;
    for (int e = 1; e < vCnt; ++e)
    {
        std::cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    dfs();
    std::cout << msg[totalMove & 1] << '\n';
    return (0);
}
