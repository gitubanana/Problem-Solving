#include <stdio.h>
#include <vector>
#include <queue>

struct Edge {
    int v;
    int w;

    inline bool operator<(const Edge &other) const {
        return this->w > other.w;
    }
};

using t_pq = std::priority_queue<Edge>;

enum e_node {
    START,
    END
};

const int INF = 1e9;
const int MAX_V = 1e2;

int vCnt;
int links[MAX_V];
int dists[MAX_V];
std::vector<Edge> edges[MAX_V];

inline void init(void) {
    for (int v = 0; v < vCnt; v++) {
        dists[v] = INF;
    }
}

int dijkstra(void) {
    int link = 0;
    t_pq pqs[2];

    init();
    dists[START] = 0;
    pqs[0].push({START, 0});
    while (true) {
        t_pq &curPq = pqs[link & 1];
        t_pq &nextPq = pqs[!(link & 1)];
        if (curPq.empty()) {
            break;
        }

        ++link;
        while (!curPq.empty()) {
            const Edge cur = curPq.top();
            const int &curDist = dists[cur.v];
            curPq.pop();

            if (curDist != cur.w) {
                continue;
            }

            for (const Edge &next : edges[cur.v]) {
                int &nextLink = links[next.v];
                if (!(nextLink == 0 || nextLink == link)) {
                    continue;
                }

                int &cmpDist = dists[next.v];
                int nextDist = curDist + next.w;
                if (cmpDist <= nextDist) {
                    continue;
                }

                nextLink = link;
                cmpDist = nextDist;
                nextPq.push({next.v, nextDist});
            }
        }

        if (dists[END] != INF) {
            return dists[END];
        }
    }
    return -1;
}

int main(void) {
    int eCnt;

    scanf(" %d %d", &vCnt, &eCnt);
    for (int e = 0; e < eCnt; e++) {
        int from, to, w;

        scanf(" %d %d %d", &from, &to, &w);
        edges[from].push_back({to, w});
    }
    printf("%d\n", dijkstra());
    return 0;
}
