#include <stdio.h>
#include <vector>
#include <queue>

enum e_vertex {
    START = 1,
    END
};

struct t_edge {
    int v;
    int w;

    inline bool operator<(const t_edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 1001;
const int INF = 1e9 + 1;

int vCnt;
int dp[MAX_V];
int dists[MAX_V];
std::vector<t_edge> edges[MAX_V];

inline void init(void) {
    for (int v = 1; v <= vCnt; v++) {
        dp[v] = INF;
        dists[v] = INF;
        edges[v].clear();
    }
}

void dijkstra(void) {
    std::priority_queue<t_edge> pq;

    dists[END] = 0;
    pq.push({END, 0});
    while (!pq.empty()) {
        const t_edge cur = pq.top();
        const int &curDist = dists[cur.v];
        pq.pop();

        if (cur.w != curDist) {
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

int dfs(int cur=START) {
    if (cur == END) {
        return 1;
    }
    
    int &curDp = dp[cur];
    const int &curDist = dists[cur];

    if (curDp != INF) {
        return curDp;
    }
    
    curDp = 0;
    for (const t_edge &next : edges[cur]) {
        const int &nextDist = dists[next.v];
        if (curDist <= nextDist) {
            continue;
        }

        curDp += dfs(next.v);
    }
    return curDp;
}

int main(void) {
    while (true) {
        int eCnt;

        if (fscanf(stdin, " %d %d", &vCnt, &eCnt) != 2) {
            break;
        }

        init();
        for (int e = 0; e < eCnt; e++) {
            int a, b, w;

            fscanf(stdin, " %d %d %d", &a, &b, &w);
            edges[a].push_back({b, w});
            edges[b].push_back({a, w});
        }

        dijkstra();
        fprintf(stdout, "%d\n", dfs());
    }
    return 0;
}
