#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_V = 201;
const int INF = 1e8;

int dists[MAX_V][MAX_V];

void floyd(int vCnt)
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
                }
            }
        }
    }
}

int solution(int vCnt, int s, int a, int b, vector<vector<int>> fares) {
    for (int from = 1; from <= vCnt; ++from)
    {
        for (int to = 1; to <= vCnt; ++to)
        {
            dists[from][to] = INF;
        }
    }
    for (std::vector<int> &edge : fares)
    {
        int &from = edge[0];
        int &to = edge[1];
        int &weight = edge[2];

        dists[from][to] = dists[to][from] = weight;
    }

    floyd(vCnt);

    int answer = std::min({
        dists[s][a] + dists[s][b],
        dists[s][a] + dists[a][b],
        dists[s][b] + dists[b][a]
    });

    for (int mid = 1; mid <= vCnt; ++mid)
    {
        answer = std::min(
            answer,
            dists[s][mid] + dists[mid][a] + dists[mid][b]
        );
    }

    return answer;
}
