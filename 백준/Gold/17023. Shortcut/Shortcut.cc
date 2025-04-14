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

const int MAX_V = 1e4 + 1;
const int INF = 1e9;
const int START = 1;

int vCnt;
int newTime;
int via[MAX_V];
int dists[MAX_V];
int cowCnt[MAX_V];
int indegree[MAX_V + 1];
std::vector<Edge> edges[MAX_V];

inline void init(void) {
    for (int v = 2; v <= vCnt; v++) {
        via[v] = MAX_V;
        dists[v] = INF;
    }
}

inline void setVia(int &nextVia, int newVia) {
    --indegree[nextVia];
    nextVia = newVia;
    ++indegree[nextVia];
}

void dijkstra(void) {
    std::priority_queue<Edge> pq;

    init();
    dists[START] = 0;
    pq.push({START, 0});
    while (!pq.empty()) {
        const Edge cur = pq.top();
        const int &curDist = dists[cur.v];
        pq.pop();

        if (cur.w != curDist) {
            continue;
        }

        for (const Edge &next : edges[cur.v]) {
            int &cmpDist = dists[next.v];
            int nextDist = curDist + next.w;
            if (cmpDist < nextDist) {
                continue;
            }

            int &nextVia = via[next.v];
            if (cmpDist == nextDist) {
                if (nextVia > cur.v) {
                    setVia(nextVia, cur.v);
                }
                continue;
            }

            setVia(nextVia, cur.v);
            cmpDist = nextDist;
            pq.push({next.v, nextDist});
        }
    }
}

void topologicalSort(void) {
    std::queue<int> q;

    for (int v = 1; v <= vCnt; v++) {
        if (indegree[v] == 0) {
            q.push(v);
        }
    }
    while (!q.empty()) {
        const int cur = q.front();
        const int &next = via[cur];
        q.pop();

        cowCnt[next] += cowCnt[cur];
        if (--indegree[next] == 0) {
            q.push(next);
        }
    }
}

long long findMaxReduction(void) {
    long long max = 0;

    for (int v = 2; v <= vCnt; v++) {
        long long shortenedTime = static_cast<long long>(dists[v]) - newTime;
        if (shortenedTime <= 0) {
            continue;
        }

        max = std::max(max, shortenedTime * cowCnt[v]);
    }
    return max;
}

int main(void) {
    int eCnt;

    fscanf(stdin, " %d %d %d", &vCnt, &eCnt, &newTime);
    for (int v = 1; v <= vCnt; v++) {
        fscanf(stdin, " %d", &cowCnt[v]);
    }
    for (int e = 0; e < eCnt; e++) {
        int a, b, w;
    
        fscanf(stdin, " %d %d %d", &a, &b, &w);
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    dijkstra();
    topologicalSort();
    fprintf(stdout, "%lld\n", findMaxReduction());
    return 0;
}
