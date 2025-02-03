#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>

struct t_edge {
    int v;
    int w;

    inline bool operator<(const t_edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 500;
const int INF = 1e9;
const int VISITED = -1;

int vCnt;
int start, end;
int dists[MAX_V];
bool removed[MAX_V][MAX_V];
std::vector<int> prevs[MAX_V];
std::vector<t_edge> edges[MAX_V];

inline void initEdges() {
    memset(removed, false, sizeof(removed));
    for (int v = 0; v < vCnt; v++) {
        prevs[v].clear();
        edges[v].clear();
    }
}

inline void initDists() {
    for (int v = 0; v < vCnt; v++) {
        dists[v] = INF;
    }
}

void makeShortestPath() {
    std::priority_queue<t_edge> pq;

    initDists();
    dists[start] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        const t_edge cur = pq.top();
        const int &curDist = dists[cur.v];
        pq.pop();

        if (curDist != cur.w) {
            continue;
        }

        for (const t_edge &next : edges[cur.v]) {
            int &nextDist = dists[next.v];
            int cmpDist = curDist + next.w;

            if (nextDist > cmpDist) {
                nextDist = cmpDist;
                prevs[next.v].clear();
                pq.push({next.v, nextDist});
            }

            if (nextDist == cmpDist) {
                prevs[next.v].push_back(cur.v);
            }
        }
    }
}

void removeShortestPath(int cur) {
    dists[cur] = VISITED;
    for (const int &prev : prevs[cur]) {
        removed[prev][cur] = true;
        if (dists[prev] == VISITED) {
            continue;
        }

        removeShortestPath(prev);
    }
}

int secondShortestPath() {
    std::priority_queue<t_edge> pq;

    initDists();
    dists[start] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        const t_edge cur = pq.top();
        const int &curDist = dists[cur.v];
        pq.pop();

        if (curDist != cur.w) {
            continue;
        }

        for (const t_edge &next : edges[cur.v]) {
            if (removed[cur.v][next.v]) {
                continue;
            }

            int &nextDist = dists[next.v];
            int cmpDist = curDist + next.w;
            if (nextDist <= cmpDist) {
                continue;
            }

            nextDist = cmpDist;
            pq.push({next.v, nextDist});
        }
    }
    return dists[end] == INF ? -1 : dists[end];
}

int main(void) {
    while (true) {
        int eCnt;

        fscanf(stdin, " %d %d", &vCnt, &eCnt);
        if (vCnt == 0) {
            break;
        }

        initEdges();
        fscanf(stdin, " %d %d", &start, &end);
        while (eCnt-- > 0) {
            int from, to, w;

            fscanf(stdin, " %d %d %d", &from, &to, &w);
            edges[from].push_back({to, w});
        }

        makeShortestPath();
        removeShortestPath(end);
        fprintf(stdout, "%d\n", secondShortestPath());
    }

    return 0;
}
