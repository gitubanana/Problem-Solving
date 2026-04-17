#include <stdio.h>
#include <algorithm>
#include <cstring>

const int BURP = 0;
const int MAX_SIZE = 40;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int cnt[MAX_SIZE][MAX_SIZE];

class Pos {
public:
    int y, x;

    inline bool outOfBoundary(void) const {
        return y == -1 || y == ySize
            || x == -1 || x == xSize;
    }

    inline bool operator!=(const Pos &other) const {
        return this->y != other.y || this->x != other.x;
    }

    inline bool operator<(const Pos &other) const {
        return cnt[this->y][this->x] < cnt[other.y][other.x];
    }
};

int main(void) {
    scanf(" %d %d", &ySize, &xSize);
    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            scanf(" %d", &cnt[y][x]);
        }
    }

    Pos cur = {0, 0};
    Pos end = {ySize - 1, xSize - 1};
    int eatenCnt = cnt[end.y][end.x];

    do {
        int &papayaCnt = cnt[cur.y][cur.x];

        eatenCnt += papayaCnt;
        papayaCnt = BURP;

        Pos next = cur;
        for (int dir = 0; dir < dirSize; dir++) {
            Pos cmp = {cur.y + dy[dir], cur.x + dx[dir]};
            if (cmp.outOfBoundary()) {
                continue;
            }

            next = std::max(next, cmp);
        }
        cur = next;
    } while (cur != end);
    printf("%d\n", eatenCnt);
    return 0;
}
