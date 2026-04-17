#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>

class Edge {
public:
    int v, w;

    inline bool operator<(const Edge &other) const {
        return this->w < other.w;
    }
};

const int MAX_V = 1e3 + 1;
const int INF = 1e9;

int vCnt;
int start, end;
int bw[MAX_V];
std::vector<Edge> edges[MAX_V];

inline void init(void) {
    for (int v = 1; v <= vCnt; v++) {
        edges[v].clear();
        bw[v] = 0;
    }
}

int dijkstra(void) {
    std::priority_queue<Edge> pq;

    bw[start] = INF;
    pq.push({start, INF});
    do {
        const Edge cur = pq.top();
        const int &curBw = bw[cur.v];
        pq.pop();

        if (curBw != cur.w) {
            continue;
        }

        if (cur.v == end) {
            return curBw;
        }

        for (const Edge &next : edges[cur.v]) {
            int &cmpBw = bw[next.v];
            int nextBw = std::min(curBw, next.w);
            if (cmpBw >= nextBw) {
                continue;
            }

            cmpBw = nextBw;
            pq.push({next.v, nextBw});
        }
    } while (!pq.empty());

    throw std::exception();
    return -1;
}

int main(void) {
    int testCnt;

    scanf(" %d", &testCnt);
    for (int t = 0; t < testCnt; t++) {
        int eCnt;

        scanf(" %d %d %d %d", &vCnt, &eCnt, &start, &end);
        init();
        for (int e = 0; e < eCnt; e++) {
            int a, b, w;

            scanf(" %d %d %d", &a, &b, &w);
            edges[a].push_back({b, w});
            edges[b].push_back({a, w});
        }

        printf("%d\n", dijkstra());
    }
    return 0;
}


