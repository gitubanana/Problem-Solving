#include <stdio.h>
#include <vector>
#include <queue>

struct Edge {
    int v;
    long w;

    inline bool operator<(const Edge &other) const {
        return this->w > other.w;
    }
};

using t_pq = std::priority_queue<Edge>;

const int MAX_V = 1e5 + 1;
const int DIVISOR = 1e9 + 9;
const long INF = 2e10 + 1;

int vCnt;
int start, end;
int cnt[MAX_V];
int transfer[MAX_V];
long dists[MAX_V];
std::vector<Edge> edges[MAX_V];

inline void init(void) {
    for (int v = 1; v <= vCnt; v++) {
        transfer[v] = DIVISOR;
        dists[v] = INF;
    }
}

void dijkstra() {
    t_pq pq;

    init();
    cnt[start] = 1;
    dists[start] = transfer[start] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        const Edge cur = pq.top();
        const int &curTransfer = transfer[cur.v];
        const long &curDist = dists[cur.v];
        pq.pop();

        if (cur.w != curDist) {
            continue;
        }

        for (const Edge &next : edges[cur.v]) {
            long &cmpDist = dists[next.v];
            long nextDist = curDist + next.w;
            if (cmpDist < nextDist) {
                continue;
            }

            int &cmpTransfer = transfer[next.v];
            int nextTransfer = curTransfer + 1;
            if (cmpDist == nextDist) {
                if (cmpTransfer == nextTransfer) {
                    cnt[next.v] += cnt[cur.v];
                    cnt[next.v] %= DIVISOR;
                } else if (cmpTransfer > nextTransfer) {
                    cnt[next.v] = cnt[cur.v];
                    cmpTransfer = nextTransfer;
                    pq.push({next.v, nextDist});
                }
                continue;
            }

            cmpDist = nextDist;
            cnt[next.v] = cnt[cur.v];
            cmpTransfer = nextTransfer;
            pq.push({next.v, nextDist});
        }
    }
}

int main(void) {
    int eCnt;

    fscanf(stdin, " %d %d %d %d", &vCnt, &eCnt, &start, &end);
    for (int e = 0; e < eCnt; e++) {
        int from, to, w;

        fscanf(stdin, " %d %d %d", &from, &to, &w);
        edges[from].push_back({to, w});
    }

    dijkstra();
    if (dists[end] == INF) {
        fprintf(stdout, "-1\n");
    } else {
        fprintf(stdout, "%ld\n%d\n%d\n", dists[end], transfer[end], cnt[end]);
    }
    return 0;
}
