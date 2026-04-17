#include <stdio.h>
#include <vector>
#include <queue>

using ll = long long;

struct Edge {
    int v;
    int length;
    int cost;
};

struct Move {
    int v;
    ll length;

    inline bool operator<(const Move &other) const {
        return this->length > other.length;
    }
};

const int START = 1;
const int MAX_V = 1e4 + 1;
const long INF = 1e13 + 1;

int vCnt;
ll lengths[MAX_V];
int usedEdges[MAX_V];
std::vector<Edge> edges[MAX_V];

inline void init(void) {
    for (int v = START + 1; v <= vCnt; v++) {
        lengths[v] = INF;
    }
}

void dijkstra(void) {
    std::priority_queue<Move> pq;

    init();
    pq.push({START, 0});
    while (!pq.empty()) {
        const Move cur = pq.top();
        const ll &curLength = lengths[cur.v];
        pq.pop();

        if (cur.length != curLength) {
            continue;
        }

        for (const Edge &next : edges[cur.v]) {
            ll &cmpLength = lengths[next.v];
            ll nextLength = curLength + next.length;
            if (cmpLength < nextLength) {
                continue;
            }

            if (cmpLength == nextLength) {
                usedEdges[next.v] = std::min(usedEdges[next.v], next.cost);
                continue;
            }

            cmpLength = nextLength;
            usedEdges[next.v] = next.cost;
            pq.push({next.v, nextLength});
        }
    }
}

int main(void) {
    int eCnt;

    fscanf(stdin, " %d %d", &vCnt, &eCnt);
    for (int e = 0; e < eCnt; e++) {
        int a, b, l, c;

        fscanf(stdin, " %d %d %d %d", &a, &b, &l, &c);
        edges[a].push_back({b, l, c});
        edges[b].push_back({a, l, c});
    }
    
    ll ans = 0;

    dijkstra();
    for (int v = START + 1; v <= vCnt; v++) {
        ans += usedEdges[v];
    }
    fprintf(stdout, "%lld\n", ans);
    return 0;
}
