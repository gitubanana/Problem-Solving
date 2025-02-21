#include <stdio.h>
#include <vector>
#include <queue>

struct t_edge {
    int v;
    int w;
    int wearDown;

    inline bool operator<(const t_edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 2000 + 1;
const int MAX_HULL = 200 + 1;
const int INF = 1e9;

int vCnt;
int hullSize;
int start, end;
int dists[MAX_V][MAX_HULL];
std::vector<t_edge> edges[MAX_V];

int dijkstra(int start, int end) {
    std::priority_queue<t_edge> pq;

    for (int v = 1; v <= vCnt; v++) {
        for (int h = 0; h < hullSize; h++) {
            dists[v][h] = INF;
        }
    }

    dists[start][0] = 0;
    pq.push({start, 0, 0});
    while (!pq.empty()) {
        const t_edge cur = pq.top();
        const int &curDist = dists[cur.v][cur.wearDown];
        pq.pop();

        if (cur.w != curDist) {
            continue;
        }

        if (cur.v == end) {
            return curDist;
        }

        for (const t_edge &next : edges[cur.v]) {
            int nextWearDown = cur.wearDown + next.wearDown;
            if (nextWearDown >= hullSize) {
                continue;
            }

            int &nextDist = dists[next.v][nextWearDown];
            int cmpDist = curDist + next.w;
            if (nextDist <= cmpDist) {
                continue;
            }

            nextDist = cmpDist;
            pq.push({next.v, nextDist, nextWearDown});
        }
    }
    return -1;
}

int main(void) {
    int eCnt;

    fscanf(stdin, " %d %d %d", &hullSize, &vCnt, &eCnt);
    while (eCnt-- > 0) {
        int a, b, w, h;

        fscanf(stdin, " %d %d %d %d", &a, &b, &w, &h);
        edges[a].push_back({b, w, h});
        edges[b].push_back({a, w, h});
    }

    fscanf(stdin, " %d %d", &start, &end);
    fprintf(stdout, "%d\n", dijkstra(start, end));
    return 0;
}
