#include <stdio.h>
#include <vector>
#include <queue>

struct t_edge {
    int v;
    int w;
    int yum;
};

struct t_dijk {
    int v;
    int w;
    bool eaten;

    inline bool operator<(const t_dijk &other) const {
        if (this->w == other.w) {
            return !other.eaten;
        }
        return this->w > other.w;
    }
};

const int MAX_V = 1e5 + 1;
const int INF = 2e9 + 1;
const int START = 1;

int vCnt;
int dists[MAX_V][2];
std::vector<t_edge> edges[MAX_V];

void dijkstra() {
    std::priority_queue<t_dijk> pq;

    for (int v = 1; v <= vCnt; v++) {
        dists[v][0] = dists[v][1] = INF;
    }

    dists[START][0] = 0;
    pq.push({START, 0, false});
    while (!pq.empty()) {
        const t_dijk cur = pq.top();
        const int &curDist = dists[cur.v][cur.eaten];
        pq.pop();

        if (cur.w != curDist) {
            continue;
        }

        for (const t_edge &next : edges[cur.v]) {
            for (int eat = 0; eat <= 1; eat++) {
                if (cur.eaten && eat) {
                    break;
                }

                bool nextEaten = cur.eaten | eat;
                int &nextDist = dists[next.v][nextEaten];
                int cmpDist = curDist + next.w - (eat * next.yum);
                if (nextDist <= cmpDist) {
                    continue;
                }

                nextDist = cmpDist;
                pq.push({next.v, nextDist, nextEaten});
            }
        }
    }
}

int main(void) {
    int eCnt;

    fscanf(stdin, " %d %d", &vCnt, &eCnt);
    while (eCnt-- > 0) {
        int a, b, w, yum;

        fscanf(stdin, " %d %d %d %d", &a, &b, &w, &yum);
        edges[a].push_back({b, w, yum});
        edges[b].push_back({a, w, yum});
    }

    dijkstra();

    for (int v = 2; v <= vCnt; v++) {
        fprintf(stdout, "%d\n", std::min(dists[v][0], dists[v][1]));
    }
    return 0;
}
