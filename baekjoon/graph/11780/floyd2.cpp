#include <iostream>
#include <vector>

const int MAX_V = 101;
const int INF = 1e9;

int vCnt;
int dists[MAX_V][MAX_V];
int through[MAX_V][MAX_V];
std::vector<int> path;

void    floyd2(void)
{
    for (int mid = 1; mid <= vCnt; ++mid)
    {
        for (int from = 1; from <= vCnt; ++from)
        {
            for (int to = 1; to <= vCnt; ++to)
            {
                if (from == to)
                    continue ;

                int &cmpDist = dists[from][to];
                int nextDist = dists[from][mid] + dists[mid][to];

                if (cmpDist > nextDist)
                {
                    cmpDist = nextDist;
                    through[from][to] = through[from][mid];
                }
            }
        }
    }
}

void    findPath(int from, int to)
{
    path.push_back(from);

    int cur = through[from][to];
    while (cur != to)
    {
        path.push_back(cur);
        cur = through[cur][to];
    }

    path.push_back(to);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    for (int from = 1; from <= vCnt; ++from)
    {
        for (int to = 1; to <= vCnt; ++to)
        {
            dists[from][to] = INF;
        }
    }
    while (eCnt--)
    {
        int from, to, newDist;

        std::cin >> from >> to >> newDist;

        int &cmpDist = dists[from][to];
        if (cmpDist > newDist)
        {
            cmpDist = newDist;
            through[from][to] = to;
        }
    }

    floyd2();

    for (int from = 1; from <= vCnt; ++from)
    {
        for (int to = 1; to <= vCnt; ++to)
        {
            int &curDist = dists[from][to];

            std::cout << (curDist == INF ? 0 : curDist) << ' ';
        }
        std::cout << '\n';
    }

    for (int from = 1; from <= vCnt; ++from)
    {
        for (int to = 1; to <= vCnt; ++to)
        {
            if (dists[from][to] == INF)
            {
                std::cout << "0" << '\n';
                continue ;
            }

            path.clear();
            findPath(from, to);

            std::cout << path.size() << ' ';
            for (const int &cur : path)
            {
                std::cout << cur << ' ';
            }
            std::cout << '\n';
        }
    }
    return (0);
}
