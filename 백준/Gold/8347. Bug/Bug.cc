#include <stdio.h>
#include <queue>
#define END vCnt

class Edge {
public:
    int v, w;

    inline bool operator<(const Edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 2e5 + 1;
const int START = 1;
const int INF = 1e9;

int vCnt;
int dists[MAX_V][2];
std::vector<Edge> edges[MAX_V];

int dijkstra() {
    std::priority_queue<Edge> pq;

    for (int v = 1; v <= vCnt; v++) {
        dists[v][0] = dists[v][1] = INF;
    }

    dists[START][0] = 0;
    pq.push({START, 0});
    do {
        const Edge cur = pq.top();
        bool isOdd = cur.w & 1;
        const int &curDist = dists[cur.v][isOdd];
        pq.pop();

        if (cur.w != curDist) {
            continue;
        }

        if (cur.v == END && isOdd) {
            return curDist;
        }

        for (const Edge &next : edges[cur.v]) {
            int nextDist = curDist + next.w;
            bool nextIsOdd = nextDist & 1;
            int &cmpDist = dists[next.v][nextIsOdd];
            if (cmpDist <= nextDist) {
                continue;
            }

            cmpDist = nextDist;
            pq.push({next.v, nextDist});
        }

    } while (!pq.empty());

    return 0;
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

    printf("%d\n", dijkstra());
    return 0;
}
