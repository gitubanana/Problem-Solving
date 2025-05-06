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
    int vCnt, eCnt, oneEdge;
    scanf(" %d %d %d", &vCnt, &eCnt, &oneEdge);

    UnionFind uf(vCnt);
    for (int e = 1; e <= eCnt; e++) {
        int a, b;

        scanf(" %d %d", &a, &b);
        if (e == oneEdge) {
            continue;
        }

        uf.group(a, b);
    }

    long long oneSize = uf.sizeOf(1);
    printf("%lld\n", oneSize * (vCnt - oneSize));
    return 0;
}
