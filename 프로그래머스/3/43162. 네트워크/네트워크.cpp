#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MAX_V = 200;

int vCnt;
vector<int> *isLinked;
bool visited[MAX_V];

void    dfs(int cur)
{
    visited[cur] = true;
    for (int next = 0; next < vCnt; ++next)
    {
        if (!isLinked[cur][next] || visited[next])
            continue ;

        dfs(next);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vCnt = n;
    isLinked = &computers[0];
    for (int v = 0; v < vCnt; ++v)
    {
        if (visited[v])
            continue ;

        ++answer;
        dfs(v);
    }
    return answer;
}