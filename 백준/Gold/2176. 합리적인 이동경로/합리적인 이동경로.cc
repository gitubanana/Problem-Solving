#include <iostream>
#include <cstring>
#include <queue>

struct t_edge {
    int v;
    int w;

    inline bool operator<(const t_edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 1000 + 1;
const int INF = 1e9 + 1;
const int START = 1;
const int END = 2;
const int INIT = -1;

int vCnt;
int dp[MAX_V];
int dists[MAX_V];
std::vector<t_edge> edges[MAX_V];

void dijkstra(int start) {
    std::priority_queue<t_edge> pq;

    for (int v = 1; v <= vCnt; v++) {
        dists[v] = INF;
    }

    dists[start] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        const t_edge cur = pq.top();
        const int &curDist = dists[cur.v];
        pq.pop();

        if (curDist != cur.w) {
            continue;
        }

        for (const t_edge &next : edges[cur.v]) {
            int &cmpDist = dists[next.v];
            int nextDist = curDist + next.w;

            if (cmpDist <= nextDist) {
                continue;
            }

            cmpDist = nextDist;
            pq.push({next.v, nextDist});
        }
    }
}

int dfs(int cur, int prev=0) {
    int &curDp = dp[cur];
    if (curDp != INIT) {
        return curDp;
    }

    if (cur == END) {
        return curDp = 1;
    }

    const int &curDist = dists[cur];

    curDp = 0;
    for (const t_edge &next : edges[cur]) {
        const int &nextDist = dists[next.v];
        if (next.v == prev || nextDist >= curDist) {
            continue;
        }

        curDp += dfs(next.v, cur);
    }
    return curDp;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    while (eCnt-- > 0) {
        int a, b, w;

        std::cin >> a >> b >> w;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    dijkstra(END);

    memset(dp, INIT, sizeof(dp));
    std::cout << dfs(START) << '\n';
    return 0;
}
