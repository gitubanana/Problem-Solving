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

struct t_dijk : public t_edge {
    int freeCnt;

    t_dijk(int v, int w, int freeCnt) : t_edge({v, w}) {
        this->freeCnt = freeCnt;
    }
};

const int START = 1;
const int MAX_V = 1e3 + 1;
const int INF = 1e6 + 1;

int vCnt;
int maxDists[MAX_V][MAX_V];
std::vector<t_edge> edges[MAX_V];

int dijkstra(int start, int freeCnt) {
    std::priority_queue<t_dijk> pq;

    for (int v = 1; v <= vCnt; v++) {
        for (int f = 0; f <= freeCnt; f++) {
            maxDists[v][f] = INF;
        }
    }

    maxDists[start][freeCnt] = 0;
    pq.push({start, 0, freeCnt});
    while (!pq.empty()) {
        const t_dijk cur = pq.top();
        const int &curDist = maxDists[cur.v][cur.freeCnt];
        pq.pop();

        if (cur.w != curDist) {
            continue;
        }

        for (const t_edge &next : edges[cur.v]) {
            for (int use = 0; use <= 1; use++) {
                int nextFree = cur.freeCnt - use;
                if (nextFree < 0) {
                    continue;
                }

                int &nextDist = maxDists[next.v][nextFree];
                int cmpDist = std::max(curDist, next.w * (use == 0));
                if (nextDist <= cmpDist) {
                    continue;
                }

                nextDist = cmpDist;
                pq.push({next.v, nextDist, nextFree});
            }
        }
    }

    int minDist = *std::min_element(maxDists[vCnt], maxDists[vCnt] + freeCnt + 1);
    if (minDist == INF) {
        return -1;
    }
    return minDist;
}

int main(void) {
    int eCnt, freeCnt;

    fscanf(stdin, " %d %d %d", &vCnt, &eCnt, &freeCnt);
    while (eCnt-- > 0) {
        int a, b, w;

        fscanf(stdin, " %d %d %d", &a, &b, &w);
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    fprintf(stdout, "%d\n", dijkstra(START, freeCnt));
    return 0;
}
