#include <stdio.h>
#include <vector>
#include <queue>

struct t_edge {
    int v;
    int w;

    inline bool operator<(const t_edge &other) const {
        return this->w > other.w;
    }
};

using t_pq = std::priority_queue<t_edge>;

const int MAX_V = 4000 + 1;
const int INF = 2e9;
const int START = 1;

int vCnt;
int fDists[MAX_V];
int wDists[MAX_V][2];
std::vector<t_edge> edges[MAX_V];

inline void initDists(void) {
    for (int v = 1; v <= vCnt; v++) {
        fDists[v] = wDists[v][0] = wDists[v][1] = INF;
    }
}

void foxDijkstra(int dists[]) {
    t_pq pq;

    dists[START] = 0;
    pq.push({START, 0});
    while (!pq.empty()) {
        const t_edge cur = pq.top();
        const int &curDist = dists[cur.v];
        pq.pop();

        if (cur.w != curDist) {
            continue;
        }

        for (const t_edge &next : edges[cur.v]) {
            int &nextDist = dists[next.v];
            int cmpDist = curDist + next.w;
            if (nextDist <= cmpDist) {
                continue;
            }

            nextDist = cmpDist;
            pq.push({next.v, nextDist});
        }
    }
}

inline int getWeight(int w, int idx) {
    return idx == 0 ? w / 2 : w * 2; 
}

void wolfDijkstra(int dists[][2]) {
    int idx = 0;
    t_pq pqs[2];

    dists[START][0] = 0;
    pqs[0].push({START, 0});
    while (true) {
        int nextIdx = idx ^ 1;
        t_pq &pq = pqs[idx];
        t_pq &nextPq = pqs[nextIdx];
        if (pq.empty()) {
            break;
        }

        while (!pq.empty()) {
            const t_edge cur = pq.top();
            const int &curDist = dists[cur.v][idx];
            pq.pop();
    
            if (cur.w != curDist) {
                continue;
            }
    
            for (const t_edge &next : edges[cur.v]) {
                int &nextDist = dists[next.v][nextIdx];
                int cmpDist = curDist + getWeight(next.w, idx);
                if (nextDist <= cmpDist) {
                    continue;
                }

                nextDist = cmpDist;
                nextPq.push({next.v, nextDist});
            }
        }

        idx = nextIdx;
    }
}

inline int countFasterFox() {
    int cnt = 0;

    for (int v = 1; v <= vCnt; v++) {
        cnt += (fDists[v] < std::min(wDists[v][0], wDists[v][1]));
    }
    return cnt;
}

int main(void) {
    int eCnt;

    fscanf(stdin, " %d %d", &vCnt, &eCnt);
    while (eCnt-- > 0) {
        int a, b, w;

        fscanf(stdin, " %d %d %d", &a, &b, &w);
        w <<= 1;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    initDists();
    foxDijkstra(fDists);
    wolfDijkstra(wDists);
    fprintf(stdout, "%d\n", countFasterFox());
    return 0;
}
