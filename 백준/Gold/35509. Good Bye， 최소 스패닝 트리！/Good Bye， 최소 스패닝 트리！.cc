// love you, BOJ
#include <vector>
#include <iostream>
#include <algorithm>

using ll = long long;

const int MAX_V = 100001;
const int INF = 1e9 + 1;

class UnionFind {
private:
    int vCnt;
    int *parents;

public:
    UnionFind(int vCnt) : vCnt(vCnt), parents(new int[vCnt+1]) {
        for (int v = 1; v <= vCnt; v++) {
            parents[v] = v;
        }
    }
    ~UnionFind() { delete[] parents; }

    int parentOf(int v) {
        int &curP = parents[v];
        if (curP == v) {
            return v;
        }
        return curP = parentOf(curP);
    }

    void group(int x, int y) {
        parents[parentOf(x)] = parents[parentOf(y)];
    }
};

class Edge {
public:
    int a, b;
    int w, id;

    inline bool operator<(const Edge &other) const {
        return this->w < other.w;
    }
};

int vCnt;
int mstMax;
ll mstTotal;
std::vector<Edge> edges;

inline std::istream &operator>>(std::istream &in, Edge &edge) {
    return in >> edge.a >> edge.b >> edge.w;
}

void mst() {
    int madeEcnt = 1;
    UnionFind uf(vCnt);

    std::sort(edges.begin(), edges.end());
    for (const Edge &edge : edges) {
        if (uf.parentOf(edge.a) == uf.parentOf(edge.b)) {
            continue;
        }

        mstTotal += edge.w;
        mstMax = std::max(mstMax, edge.w);
        if (++madeEcnt == vCnt) {
            return;
        }

        uf.group(edge.a, edge.b);
    }
}

void mbst() {
    int madeEcnt = 1;
    ll mbstTotal = 0;
    UnionFind uf(vCnt);
    std::vector<int> ids;

    for (int i = edges.size()-1; i >= 0; i--) {
        const Edge &edge = edges[i];
        if (edge.w > mstMax || uf.parentOf(edge.a) == uf.parentOf(edge.b)) {
            continue;
        }

        mbstTotal += edge.w;
        ids.push_back(edge.id);
        if (++madeEcnt == vCnt) {
            break;
        }

        uf.group(edge.a, edge.b);
    }

    if (madeEcnt != vCnt || mbstTotal == mstTotal) {
        std::cout << "NO" << '\n';
        return;
    }

    std::cout << "YES" << '\n';
    for (const int &id : ids) {
        std::cout << id << '\n';
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;
    Edge edge;

    std::cin >> vCnt >> eCnt;
    for (int e = 1; e <= eCnt; e++) {
        std::cin >> edge;
        edge.id = e;
        edges.push_back(edge);
    }

    std::cout << "NO" << '\n';
    mst();
    mbst();
    return 0;
}