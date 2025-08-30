#include <vector>
#include <iostream>
#include <algorithm>

class UnionFind {
private:
    int *parents;
public:
    UnionFind(int vCnt) : parents(new int[vCnt+1]) {
        for (int v = 1; v <= vCnt; v++) {
            parents[v] = v;
        }
    }

    ~UnionFind() {
        delete[] parents;
    }

    int parentOf(int v) {
        int &parent = parents[v];
        if (parent == v) {
            return v;
        }
        return parent = parentOf(parent);
    }

    void group(int x, int y) {
        parents[parentOf(x)] = parentOf(y);
    }
};

class Edge {
public:
    int a, b, w;

    inline bool operator<(const Edge &other) const {
        return this->w < other.w;
    }
};

inline std::istream &operator>>(std::istream &in, Edge &edge) {
    in >> edge.a >> edge.b >> edge.w;
    return in;
}

int kruskal(int vCnt, std::vector<Edge> &edges) {
    int totalLength = 0;
    int madeEcnt = 1;
    UnionFind uf(vCnt);

    std::sort(edges.begin(), edges.end());
    for (const Edge &edge : edges) {
        if (uf.parentOf(edge.a) == uf.parentOf(edge.b)) {
            continue;
        }

        uf.group(edge.a, edge.b);
        totalLength += edge.w;
        if (++madeEcnt == vCnt) {
            return totalLength;
        }
    }

    return INT32_MAX;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt, eCnt, builtCnt;
    int maxLength = 0;
    std::cin >> vCnt >> eCnt >> builtCnt;

    std::vector<Edge> edges(eCnt);

    for (int e = 0; e < eCnt; e++) {
        std::cin >> edges[e];
        if (e < builtCnt) {
            maxLength += edges[e].w;
        }
    }

    const char *msg[] = {"impossible", "possible"};
    std::cout << msg[maxLength >= kruskal(vCnt, edges)] << '\n';
    return 0;
}
