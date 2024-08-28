#include <string>
#include <climits>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_V = 101;

int connectCnt[MAX_V];
std::vector<int> edges[MAX_V];

void    dfs(int cur=1, int prev=-1)
{
    connectCnt[cur] = 1;
    for (const int &next : edges[cur])
    {
        if (next == prev)
            continue ;

        dfs(next, cur);
        connectCnt[cur] += connectCnt[next];
    }
}

int solution(int vCnt, vector<vector<int>> wires) {
    for (const std::vector<int> &edge : wires)
    {
        const int &from = edge[0];
        const int &to = edge[1];

        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    int answer = INT_MAX;

    dfs();
    for (int v = 1; v <= vCnt; ++v)
    {
        answer = std::min(
            answer,
            std::abs(connectCnt[v] - (vCnt - connectCnt[v]))
        );
    }
    return answer;
}
