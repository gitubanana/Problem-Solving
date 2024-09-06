#include <iostream>

const int MAX_V = 401;
const int INF = 1e8;

int vCnt;
bool isHistory[MAX_V][MAX_V];

void floyd()
{
    for (int mid = 1; mid <= vCnt; ++mid)
    {
        for (int from = 1; from <= vCnt; ++from)
        {
            for (int to = 1; to <= vCnt; ++to)
            {
                isHistory[from][to] |= isHistory[from][mid] & isHistory[mid][to];
            }
        }
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    while (eCnt--)
    {
        int from, to;

        std::cin >> from >> to;
        isHistory[from][to] = true;
    }

    floyd();

    int qCnt;

    std::cin >> qCnt;
    while (qCnt--)
    {
        int a, b;

        std::cin >> a >> b;
        if (isHistory[a][b])
            std::cout << -1;
        else if (isHistory[b][a])
            std::cout << 1;
        else
            std::cout << 0;

        std::cout << '\n';
    }
    return 0;
}
