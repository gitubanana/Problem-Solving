#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

// Sollin algorithm

const int MAX_V = 50 + 1;

struct t_edge {
    int v;
    int w;

    inline bool operator<(const t_edge &other) const {
        return this->w > other.w;
    }
};

int vCnt;
int parents[MAX_V];
std::priority_queue<t_edge> edges[MAX_V];

inline void init() {
    for (int v = 1; v <= vCnt; v++) {
        parents[v] = v;
        edges[v] = std::priority_queue<t_edge>();
    }
}

int getParent(int x) {
    int &xParent = parents[x];
    if (xParent != x) {
        xParent = getParent(xParent);
    }
    return xParent;
}

void group(int y, int x) {
    int parent = getParent(y);
    int child = getParent(x);

    if (edges[parent].size() < edges[child].size()) {
        std::swap(parent, child);
    }

    std::priority_queue<t_edge> &parentEdges = edges[parent];
    std::priority_queue<t_edge> &childEdges = edges[child];

    while (!childEdges.empty()) {
        parentEdges.push(childEdges.top());
        childEdges.pop();
    }

    parents[child] = parents[parent];
}

int sollin() {
    int madeEcnt = 0;
    int maxEcnt = vCnt - 1;
    int totalWeight = 0;

    while (madeEcnt < maxEcnt) {
        for (int v = 1; v <= vCnt; v++) {
            if (edges[v].empty()) {
                continue;
            }

            const t_edge edge = edges[v].top();
            edges[v].pop();

            if (v == getParent(edge.v)) {
                continue;
            }

            group(v, edge.v);
            totalWeight += edge.w;
            ++madeEcnt;
        }
    }
    return totalWeight;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;
    int a, b, w;

    while (true) {
        std::cin >> vCnt;
        if (vCnt == 0) {
            break;
        }

        init();
        std::cin >> eCnt;
        while (eCnt-- > 0) {
            std::cin >> a >> b >> w;
            edges[a].push({b, w});
            edges[b].push({a, w});
        }

        std::cout << sollin() << '\n';
    }
    return 0;
}
