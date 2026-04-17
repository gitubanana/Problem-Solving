#include <stdio.h>
#include <queue>

enum e_space {
    SPIDER = 'S',
    TREE = 'T'
};

const int MAX_SIZE = 1 << 8;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE];

class Pos {
public:
    int y, x;

    inline bool outOfBoundary(void) const {
        return y < 0 || y >= ySize
            || x < 0 || x >= xSize;
    }
};

void spreadEggs(void) {
    std::queue<Pos> q;

    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            if (map[y][x] == SPIDER) {
                q.push({y, x});
            }
        }
    }

    while (!q.empty()) {
        const Pos cur = q.front();
        q.pop();

        for (int dir = 0; dir < dirSize; dir++) {
            const Pos next = {cur.y+dy[dir], cur.x+dx[dir]};
            if (next.outOfBoundary() || map[next.y][next.x] != TREE) {
                continue;
            }

            map[next.y][next.x] = SPIDER;
            q.push(next);
        }
    }
}

int main(void) {
    while (true) {
        scanf(" %d %d", &xSize, &ySize);
        if (xSize == 0) {
            break;
        }

        for (int y = 0; y < ySize; y++) {
            scanf(" %s", map[y]);
        }

        spreadEggs();

        for (int y = 0; y < ySize; y++) {
            printf("%s\n", map[y]);
        }
    }
    return 0;
}
