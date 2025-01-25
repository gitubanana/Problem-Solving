#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <queue>

struct t_edge {
    int v;
    int w;

    inline bool operator<(const t_edge &other) const {
        return this->v < other.v;
    }
};

using t_umap = std::unordered_map<int, int>;

const int MAX_V = 101;

int vCnt;
int indegree[MAX_V];
bool visited[MAX_V];
int cnt[MAX_V][MAX_V];
std::vector<t_edge> edges[MAX_V];

void dfs(int cur) {
    visited[cur] = true;

    if (edges[cur].empty()) {
        cnt[cur][cur] = 1;
    }

    for (const t_edge &next : edges[cur]) {
        if (!visited[next.v]) {
            dfs(next.v);
        }

        for (int v = 1; v < vCnt; v++) {
            if (cnt[next.v][v] == 0) {
                continue;
            }

            cnt[cur][v] += cnt[next.v][v] * next.w;
        }
    }
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    while (eCnt-- > 0) {
        int from, to, w;

        std::cin >> from >> to >> w;
        ++indegree[from];
        edges[from].push_back({to, w});
    }

    dfs(vCnt);

    for (int v = 1; v < vCnt; v++) {
        if (indegree[v] != 0) {
            continue;
        }

        std::cout << v << ' ' << cnt[vCnt][v] << '\n';
    }
    return 0;
}
