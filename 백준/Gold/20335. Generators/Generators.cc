#include <stdio.h>
#include <algorithm>
#include <vector>

const int MAX_V = 1e5 + 1;
const int VIRTUAL = 0;

struct Edge {
    int from;
    int to;
    int w;

    inline bool operator<(const Edge &other) const {
        return this->w < other.w;
    }
};

struct UnionFind {
    std::vector<int> parents;

    UnionFind(int vCnt) : parents(vCnt + 1) {
        for (int v = 0; v <= vCnt; v++) {
            parents[v] = v;
        }
    }

    int get(int x) {
        int &xParent = parents[x];
        if (x == xParent) {
            return x;
        }
        return xParent = get(xParent);
    }

    inline void group(int x, int y) {
        parents[get(x)] = parents[get(y)];
    }
};

int vCnt;
std::vector<Edge> edges;

long long kruskal(void) {
    UnionFind uf(vCnt);
    int madeEcnt = 0;
    long long totalWeight = 0;

    std::sort(edges.begin(), edges.end());
    for (const Edge &edge : edges) {
        if (uf.get(edge.from) == uf.get(edge.to)) {
            continue;
        }

        totalWeight += edge.w;
        if (++madeEcnt == vCnt) {
            return totalWeight;
        }
        uf.group(edge.from, edge.to);
    }
    return -1;
}

int main(void) {
    int eCnt;

    fscanf(stdin, " %d %d", &vCnt, &eCnt);
    for (int e = 0; e < eCnt; e++) {
        int to, w;

        fscanf(stdin, " %d %d", &to, &w);
        edges.push_back({VIRTUAL, to, w});
    }
    for (int from = 1; from <= vCnt; from++) {
        int w;

        fscanf(stdin, " %d", &w);
        edges.push_back({from, (from == vCnt ? 1 : from + 1), w});
    }

    fprintf(stdout, "%lld\n", kruskal());
    return 0;
}
