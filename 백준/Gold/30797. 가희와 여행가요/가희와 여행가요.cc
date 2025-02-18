#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

struct t_edge {
    int from;
    int to;
    int cost;
    int time_;

    inline bool operator<(const t_edge &other) const {
        if (this->cost == other.cost) {
            return this->time_ < other.time_;
        }
        return this->cost < other.cost;
    }
};

const int MAX_V = 2 * 1e5 + 1;

int vCnt;
int parents[MAX_V];
std::vector<t_edge> edges;

inline void initParents() {
    for (int v = 1; v <= vCnt; v++) {
        parents[v] = v;
    }
}

int getParent(int x) {
    int &xParent = parents[x];
    if (xParent != x) {
        xParent = getParent(xParent);
    }
    return xParent;
}

inline void group(int y, int x) {
    parents[getParent(y)] = getParent(x);
}

void kruskal() {
    int maxTime = 0;
    int madeEcnt = 1;
    long long totalCost = 0;

    initParents();
    std::sort(edges.begin(), edges.end());
    for (const t_edge &edge : edges) {
        if (getParent(edge.from) == getParent(edge.to)) {
            continue;
        }

        totalCost += edge.cost;
        maxTime = std::max(maxTime, edge.time_);
        if (++madeEcnt == vCnt) {
            fprintf(stdout, "%d %lld\n", maxTime, totalCost);
            return;
        }
        group(edge.from, edge.to);
    }

    fprintf(stdout, "-1\n");
}

int main(void) {
    int eCnt;

    fscanf(stdin, " %d %d", &vCnt, &eCnt);
    while (eCnt-- > 0) {
        t_edge edge;

        fscanf(stdin, " %d %d %d %d", &edge.from, &edge.to, &edge.cost, &edge.time_);
        edges.push_back(edge);
    }

    kruskal();
    return 0;
}
