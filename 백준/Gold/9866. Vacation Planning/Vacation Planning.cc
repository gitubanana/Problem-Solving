#include <queue>
#include <vector>
#include <stdio.h>
#include <unordered_map>

struct Edge {
    int v;
    int w;

    inline bool operator<(const Edge &other) const {
        return this->w > other.w;
    }
};

const int MAX_V = 2e4 + 1;
const int MAX_HUB = 2e2;
const int INF = 1e9;

int vCnt;
int hubCnt;
int dists[MAX_HUB][MAX_V];
std::unordered_map<int, int> hubs;
std::vector<Edge> edges[MAX_V];

inline void init(int dist[MAX_V]) {
    for (int v = 1; v <= vCnt; v++) {
        dist[v] = INF;
    }
}

void dijkstra(int start, int dist[MAX_V]) {
    std::priority_queue<Edge> pq;

    init(dist);
    dist[start] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        const Edge cur = pq.top();
        const int &curDist = dist[cur.v];
        pq.pop();

        if (cur.w != curDist) {
            continue;
        }

        for (const Edge &next : edges[cur.v]) {
            int &cmpDist = dist[next.v];
            int nextDist = curDist + next.w;
            if (cmpDist <= nextDist) {
                continue;
            }

            cmpDist = nextDist;
            pq.push({next.v, nextDist});
        }
    }
}

int calculateCost(int start, int end) {
    std::unordered_map<int, int>::iterator it = hubs.find(start);
    if (it != hubs.end()) {
        return dists[it->second][end];
    }

    int minCost = INF;
    for (const Edge &next : edges[start]) {
        int cmpCost = next.w + dists[hubs.at(next.v)][end];
        if (minCost <= cmpCost) {
            continue;
        }

        minCost = cmpCost;
    }
    return minCost;
}

int main(void) {
    int eCnt;
    int qCnt;

    fscanf(stdin, " %d %d %d %d", &vCnt, &eCnt, &hubCnt, &qCnt);
    for (int e = 0; e < eCnt; e++) {
        int from, to, w;
    
        fscanf(stdin, " %d %d %d", &from, &to, &w);
        edges[from].push_back({to, w});
    }
    for (int h = 0; h < hubCnt; h++) {
        int hub;

        fscanf(stdin, " %d", &hub);
        hubs.insert({hub, h});
    }
    for (std::pair<const int, int> &pair : hubs) {
        dijkstra(pair.first, dists[pair.second]);
    }

    int availableCnt = 0;
    long long totalMin = 0;
    for (int q = 0; q < qCnt; q++) {
        int start, end;
        fscanf(stdin, " %d %d", &start, &end);

        int cost = calculateCost(start, end);
        if (cost == INF) {
            continue;
        }

        availableCnt++;
        totalMin += cost;
    }

    fprintf(stdout, "%d\n%lld\n", availableCnt, totalMin);
    return 0;
}
