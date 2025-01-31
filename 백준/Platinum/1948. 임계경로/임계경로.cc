#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

struct t_edge {
    int v;
    int w;

    inline bool operator<(const t_edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 1e4 + 1;

int vCnt;
int weights[MAX_V];
int indegree[MAX_V];
bool visited[MAX_V];
std::vector<int> prevs[MAX_V];
std::vector<t_edge> edges[MAX_V];

int dfs(int cur) {
    int ret = prevs[cur].size();

    visited[cur] = true;
    for (const int &prev : prevs[cur]) {
        if (visited[prev]) {
            continue;
        }

        ret += dfs(prev);
    }
    return ret;
}

void topologicalSort(int start, int end) {
    std::queue<t_edge> q;

    q.push({start, 0});
    while (!q.empty()) {
        const t_edge cur = q.front();
        q.pop();

        for (const t_edge &next : edges[cur.v]) {
            int &nextWeight = weights[next.v];
            int cmpWeight = cur.w + next.w;

            if (nextWeight < cmpWeight) {
                nextWeight = cmpWeight;
                prevs[next.v].clear();
            }

            if (nextWeight == cmpWeight) {
                prevs[next.v].push_back(cur.v);
            }

            if (--indegree[next.v] != 0) {
                continue;
            }

            q.push({next.v, nextWeight});
        }
    }

    std::cout << weights[end] << '\n';
    std::cout << dfs(end) << '\n';
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    while (eCnt-- > 0) {
        int from, to, w;

        std::cin >> from >> to >> w;
        edges[from].push_back({to, w});
        ++indegree[to];
    }

    int start, end;

    std::cin >> start >> end;
    topologicalSort(start, end);
    return 0;
}
