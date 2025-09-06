#include <stdio.h>
#include <algorithm>
#include <queue>
#define END vCnt

using ll = long long;

class Edge {
public:
    int v;
    ll w;

    inline bool operator<(const Edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 1e5 + 1;
const int PATH_COUNT = 2;
const int START = 1;
const ll INF = 1e14 + 1;

int vCnt;
ll dists[MAX_V][2];
std::vector<Edge> edges[MAX_V];

ll dijkstra() {
    std::priority_queue<Edge> pq;

    for (int v = 1; v <= vCnt; v++) {
        for (int p = 0; p < PATH_COUNT; p++) {
            dists[v][p] = INF;
        }
    }

    dists[START][0] = 0;
    pq.push({START, 0});
    do {
        const Edge cur = pq.top();
        pq.pop();

        if (cur.w > dists[cur.v][PATH_COUNT - 1]) {
            continue;
        }

        if (cur.v == END && cur.w == dists[cur.v][PATH_COUNT - 1]) {
            return cur.w;
        }

        for (const Edge &next : edges[cur.v]) {
            ll &cmpDist = dists[next.v][PATH_COUNT - 1];
            ll nextDist = cur.w + next.w;
            if (cmpDist <= nextDist) {
                continue;
            }

            cmpDist = nextDist;
            std::sort(dists[next.v], dists[next.v] + PATH_COUNT);
            pq.push({next.v, nextDist});
        }
    } while (!pq.empty());

    return -1;
}

int main(void) {
    int eCnt;

    scanf(" %d %d", &vCnt, &eCnt);
    for (int e = 0; e < eCnt; e++) {
        int a, b, w;

        scanf(" %d %d %d", &a, &b, &w);
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    printf("%lld\n", dijkstra());
    return 0;
}
