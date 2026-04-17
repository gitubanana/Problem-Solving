#include <stdio.h>
#include <queue>

enum e_space {
    EMPTY = '.',
    WALL = '#',
    START = 'K',
    END = 'X'
};

const int MAX_SIZE = 100;
const int dy[] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE+1];

class Pos {
public:
    int y, x;

    inline bool outOfBoundary(void) const {
        return y < 0 || y >= ySize
            || x < 0 || x >= xSize;
    }
};

void pushStart(std::queue<Pos> &q) {
    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            if (map[y][x] == START) {
                map[y][x] = WALL;
                q.push({y, x});
                return;
            }
        }
    }
}

int bfs(void) {
    int dist = 1;
    std::queue<Pos> q;

    pushStart(q);
    do {
        for (int qSize = q.size(); qSize--; ) {
            const Pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; dir++) {
                const Pos next = {cur.y+dy[dir], cur.x+dx[dir]};
                if (next.outOfBoundary() || map[next.y][next.x] == WALL) {
                    continue;
                }

                if (map[next.y][next.x] == END) {
                    return dist;
                }

                map[next.y][next.x] = WALL;
                q.push(next);
            }
        }
        ++dist;
    } while (!q.empty());
    return -1;
}

int main(void) {
    scanf(" %d %d", &ySize, &xSize);
    for (int y = 0; y < ySize; y++) {
        scanf(" %s", map[y]);
    }

    printf("%d\n", bfs());
    return 0;
}
