#include <stdio.h>
#include <vector>

struct t_edge {
    int v;
    int w;
};

const int MAX_V = 1001;

int ans;
int vCnt;
int dp[MAX_V];
int indegree[MAX_V];
std::vector<t_edge> edges[MAX_V];

void dfs(int cur, int cmp=1) {
    int &curDp = dp[cur];
    if (curDp >= cmp) {
        return;
    }

    curDp = cmp;
    ans = std::max(ans, curDp);
    for (const t_edge &next : edges[cur]) {
        dfs(next.v, cmp + next.w);
    }
}

int main(void) {
    int eCnt;

    fscanf(stdin, " %d %d", &vCnt, &eCnt);
    for (int i = 0; i < eCnt; i++) {
        int from, to, w;

        fscanf(stdin, " %d %d %d", &from, &to, &w);
        edges[from].push_back({to, w});
        indegree[to]++;
    }

    for (int v = 1; v <= vCnt; v++) {
        if (indegree[v] != 0) {
            continue;
        }

        dfs(v);
    }
    fprintf(stdout, "%d\n", ans - 1);
    return 0;
}
