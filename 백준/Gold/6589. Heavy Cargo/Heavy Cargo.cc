#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

struct Road {
    int v;
    int u;
    int w;

    inline bool operator<(const Road &other) const {
        return this->w > other.w;
    }
};

struct Edge {
    int v;
    int w;
};

const int MAX_V =  200 + 1;

int id;
int vCnt;
int parents[MAX_V];
std::vector<Road> edges;
std::vector<Edge> mst[MAX_V];
std::unordered_map<std::string, int> nameIds;

inline void initAll(void) {
    id = 0;
    edges.clear();
    nameIds.clear();
    for (int v = 1; v <= vCnt; v++) {
        mst[v].clear();
        parents[v] = v;
    }
}

const int &getIdOf(const std::string &name) {
    int &nameId = nameIds[name];
    if (nameId == 0) {
        nameId = ++id;
    }
    return nameId;
}

int getParent(int x) {
    if (parents[x] == x) {
        return x;
    }
    return parents[x] = getParent(parents[x]);
}

inline void group(int y, int x) {
    parents[getParent(y)] = parents[getParent(x)];
}

void kruskal(void) {
    int madeEcnt = 0;

    std::sort(edges.begin(), edges.end());
    for (const Road &edge : edges) {
        if (getParent(edge.v) == getParent(edge.u)) {
            continue;
        }

        mst[edge.v].push_back({edge.u, edge.w});
        mst[edge.u].push_back({edge.v, edge.w});
        if (++madeEcnt == vCnt - 1) {
            return;
        }

        group(edge.v, edge.u);
    }
}

int dfs(int cur, int end, int prev=-1) {
    if (cur == end) {
        return 0;
    }

    for (const Edge &edge : mst[cur]) {
        if (edge.v == prev) {
            continue;
        }

        int next = dfs(edge.v, end, cur);
        if (next != -1) {
            return std::min(edge.w, next == 0 ? INT32_MAX : next);
        }
    }
    return -1;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    for (int t = 1; ; t++) {
        int eCnt;
        std::string a, b;

        std::cin >> vCnt >> eCnt;
        if (vCnt == 0) {
            break;
        }

        initAll();
        for (int e = 0; e < eCnt; e++) {
            int w;

            std::cin >> a >> b >> w;
            edges.push_back({getIdOf(a), getIdOf(b), w});
        }

        std::cin >> a >> b;
        kruskal();
        printf("Scenario #%d\n", t);
        printf("%d tons\n\n", dfs(getIdOf(a), getIdOf(b)));
    }
    return 0;
}
