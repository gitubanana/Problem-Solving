#include <stdio.h>

const int MAX_V = 1e5;

struct UnionFind {
    int vCnt;
    int *sizes;
    int *parents;

    UnionFind(int vCnt)
        : vCnt(vCnt), sizes(new int[vCnt + 1]), parents(new int[vCnt + 1]) {
        for (int v = 1; v <= vCnt; v++) {
            sizes[v] = 1;
            parents[v] = v;
        }
    }

    ~UnionFind() {
        delete[] sizes;
        delete[] parents;
    }

    inline int parentOf(int x) const {
        int &xParent = parents[x];
        if (xParent != x) {
            xParent = parentOf(xParent);
        }
        return xParent;
    }

    inline int sizeOf(int x) const {
        return sizes[parentOf(x)];
    }

    inline void group(int y, int x) {
        int &yParent = parents[parentOf(y)];
        int &xParent = parents[parentOf(x)];
        if (yParent == xParent) {
            return;
        }

        int &ySize = sizes[yParent];
        int &xSize = sizes[xParent];

        if (ySize > xSize) {
            ySize += xSize;
            xSize = 0;
            xParent = yParent;
        } else {
            xSize += ySize;
            ySize = 0;
            yParent = xParent;
        }
    }
};

int main(void) {
    int start;
    int vCnt, eCnt, oneEdge;
    scanf(" %d %d %d", &vCnt, &eCnt, &oneEdge);

    UnionFind uf(vCnt);
    for (int e = 1; e <= eCnt; e++) {
        int a, b;

        scanf(" %d %d", &a, &b);
        if (e == oneEdge) {
            start = a;
            continue;
        }

        uf.group(a, b);
    }

    long long startSize = uf.sizeOf(start);
    printf("%lld\n", startSize * (vCnt - startSize));
    return 0;
}
