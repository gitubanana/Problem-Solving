#include <stdio.h>
#include <vector>
#include <queue>

class Edge {
public:
    int v, w;

    inline bool operator<(const Edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 5e4 + 1;
const int INF = 1e9 + 1;
const int CHOCOLATE = 1;

int vCnt;
int dists[MAX_V];
std::vector<Edge> edges[MAX_V];

void dijkstra(int start) {
    std::priority_queue<Edge> pq;

    for (int v = 1; v <= vCnt; v++) {
        dists[v] = INF;
    }

    dists[start] = 0;
    pq.push({start, 0});
    do {
        const Edge cur = pq.top();
        const int &curDist = dists[cur.v];
        pq.pop();

        if (cur.w != curDist) {
            continue;
        }

        for (const Edge &next : edges[cur.v]) {
            int &cmpDist = dists[next.v];
            int nextDist = curDist + next.w;
            if (cmpDist <= nextDist) {
                continue;
            }

            cmpDist = nextDist;
            pq.push({next.v, nextDist});
        }
    } while (!pq.empty());
}

int main(void) {
    int eCnt, qCnt;

    scanf(" %d %d %d", &vCnt, &eCnt, &qCnt);
    for (int e = 0; e < eCnt; e++) {
        int from, to, w;

        scanf(" %d %d %d", &from, &to, &w);
        edges[from].push_back({to, w});
        edges[to].push_back({from, w});
    }

    dijkstra(CHOCOLATE);

    for (int q = 0; q < qCnt; q++) {
        int bull, cow;

        scanf(" %d %d", &bull, &cow);
        printf("%d\n", dists[bull] + dists[cow]);
    }
    return 0;
}
