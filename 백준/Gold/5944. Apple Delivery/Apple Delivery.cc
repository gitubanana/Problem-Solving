#include <stdio.h>
#include <vector>
#include <queue>

typedef long long ll;

class Edge {
public:
    int v;
    ll w;

    inline bool operator<(const Edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 1e5 + 1;
const ll INF = 2e9 + 1;

int vCnt;
ll dists[MAX_V];
std::vector<Edge> edges[MAX_V];

void dijkstra(int start) {
    std::priority_queue<Edge> pq;

    for (int v = 1; v <= vCnt; v++) {
        dists[v] = INF;
    }
    dists[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        const Edge cur = pq.top();
        const ll &curDist = dists[cur.v];
        pq.pop();

        if (cur.w != curDist) {
            continue;
        }

        for (const Edge &next : edges[cur.v]) {
            ll &cmpDist = dists[next.v];
            ll nextDist = curDist + next.w;
            if (cmpDist <= nextDist) {
                continue;
            }

            pq.push({next.v, cmpDist = nextDist});
        }
    }
}

int main(void) {
    int eCnt;
    int start, dest1, dest2;

    scanf(" %d %d %d %d %d", &eCnt, &vCnt,  &start, &dest1, &dest2);
    for (int e = 0; e < eCnt; e++) {
        int a, b, w;

        scanf(" %d %d %d", &a, &b, &w);
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    dijkstra(start);
    ll sTo1 = dists[dest1];
    ll sTo2 = dists[dest2];

    dijkstra(dest1);
    ll dToD = dists[dest2];

    printf("%lld\n", std::min(sTo1, sTo2) + dToD);
    return 0;
}
