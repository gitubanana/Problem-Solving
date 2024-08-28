#include <string>
#include <climits>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_V = 101;

bool visited[MAX_V];
bool checked[MAX_V][MAX_V];
std::vector<int> edges[MAX_V];

void    dfs(int cur, int &cnt)
{
    ++cnt;
    visited[cur] = true;

    for (const int &next : edges[cur])
    {
        if (visited[next])
            continue ;

        dfs(next, cnt);
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
    for (int v = 1; v <= vCnt; ++v)
    {
        for (const int &cut : edges[v])
        {
            if (checked[v][cut])
                continue ;

            memset(visited, false, sizeof(visited));
            visited[v] = visited[cut] = true;
            checked[cut][v] = true;

            int a = 0, b = 0;

            dfs(v, a);
            dfs(cut, b);

            answer = std::min(
                answer,
                std::abs(a - b)
            );
        }
    }

    return answer;
}
