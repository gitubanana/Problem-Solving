#include <iostream>
#include <climits>
#include <cstring>

struct t_edge
{
    int from;
    int to;
    int weight;
};

const int V_MAX = 501;
const int EDGE_MAX = 2500 * 2 + 200;
const int INF = 1e9;

int vCnt, eCnt;
int dists[V_MAX];
t_edge edges[EDGE_MAX];

inline std::istream &operator>>(std::istream &in, t_edge &input)
{
    in >> input.from >> input.to >> input.weight;
    return (in);
}

inline bool isPossibleToComeBackInPast(void)
{
    for (int v = 1; v <= vCnt; ++v)
    {
        dists[v] = INF;
    }
    dists[1] = 0;

    for (int i = 1; i < vCnt; ++i)
    {
        for (int e = 0; e < eCnt; ++e)
        {
            const t_edge &edge = edges[e];

            int nextDist = dists[edge.from] + edge.weight;
            if (nextDist < dists[edge.to])
                dists[edge.to] = nextDist;
        }
    }

    for (int e = 0; e < eCnt; ++e)
    {
        const t_edge &edge = edges[e];

        int nextDist = dists[edge.from] + edge.weight;
        if (nextDist < dists[edge.to])
            return (true);
    }
    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    int roadCnt, wormholeCnt;
    const char *msg[] = {"NO", "YES"};

    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> vCnt >> roadCnt >> wormholeCnt;

        int i = 0;
        while (roadCnt--)
        {
            std::cin >> edges[i];
            ++i;
            edges[i] = edges[i - 1];
            std::swap(edges[i].from, edges[i].to);
            ++i;
        }
        while (wormholeCnt--)
        {
            std::cin >> edges[i];
            edges[i].weight *= -1;
            ++i;
        }
        eCnt = i;

        std::cout << msg[isPossibleToComeBackInPast()] << '\n';
    }
    return (0);
}
