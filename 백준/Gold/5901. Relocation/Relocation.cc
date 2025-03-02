#include <stdio.h>
#include <algorithm>
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
const int MAX_MARKET = 5;
const int INF = 1e9;

int vCnt;
int minDist = INF;
bool visited[MAX_MARKET];
std::vector<int> markets;
std::vector<std::vector<int>> dists;
std::vector<std::vector<t_edge>> edges;

void dijkstra(int start, std::vector<int> &dist) {
    std::priority_queue<t_edge> pq;

    dist[start] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        const t_edge cur = pq.top();
        const int &curDist = dist[cur.v];
        pq.pop();

        if (cur.w != curDist) {
            continue;
        }

        for (const t_edge &next : edges[cur.v]) {
            int &nextDist = dist[next.v];
            int cmpDist = curDist + next.w;
            if (nextDist <= cmpDist) {
                continue;
            }

            nextDist = cmpDist;
            pq.push({next.v, nextDist});
        }
    }
}

void backTracking(int prev, int start, int curDist=0, int depth=0) {
    static const int depthLimit = markets.size();

    if (depth == depthLimit) {
        minDist = std::min(minDist, curDist + dists[prev][start]);
        return;
    }

    prev = depth == 0 ? prev : markets[prev];
    for (int next = 0; next < depthLimit; next++) {
        if (visited[next]) {
            continue;
        }

        visited[next] = true;
        backTracking(next, start, curDist + dists[next][prev], depth + 1);
        visited[next] = false;
    }
}

int main(void) {
    int eCnt, marketCnt;

    fscanf(stdin, " %d %d %d", &vCnt, &eCnt, &marketCnt);
    for (int i = 0; i < marketCnt; i++) {
        int market;

        fscanf(stdin, " %d", &market);
        markets.push_back(market);
    }

    edges = std::vector<std::vector<t_edge>>(vCnt + 1, std::vector<t_edge>());
    for (int i = 0; i < eCnt; i++) {
        int a, b, w;

        fscanf(stdin, " %d %d %d", &a, &b, &w);
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    dists = std::vector<std::vector<int>>(marketCnt, std::vector<int>(vCnt + 1, INF));
    for (int i = 0; i < marketCnt; i++) {
        dijkstra(markets[i], dists[i]);
    }

    for (int v = 1; v <= vCnt; v++) {
        if (std::find(markets.begin(), markets.end(), v) != markets.end()) {
            continue;
        }

        backTracking(v, v);
    }

    fprintf(stdout, "%d\n", minDist);
    return 0;
}
