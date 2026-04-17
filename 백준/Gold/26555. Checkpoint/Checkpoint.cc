#include <stdio.h>
#include <cstring>
#include <queue>

enum e_space {
    START = 'S',
    END = 'E',
    WALL = '#',
    EMPTY = '.'
};

const int MAX_SIZE = 11;
const int MAX_POINT = 9;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize, maxCheckPoint;
char map[MAX_SIZE][MAX_SIZE + 1];
bool visited[MAX_POINT + 1][MAX_SIZE][MAX_SIZE];

class Pos {
public:
    int p, y, x;

    inline bool outOfBoundary(void) const {
        return y == -1 || y == ySize
            || x == -1 || x == xSize;
    }
};

int bfs(void) {
    std::queue<Pos> q;
    Pos start = {0, 0, 0};

    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            if (map[y][x] == START) {
                start.y = y, start.x = x;
            }

            for (int p = 0; p <= maxCheckPoint; p++) {
                visited[p][y][x] = false;
            }
        }
    }

    int dist = 1;

    visited[start.p][start.y][start.x] = true;
    q.push(start);
    do {
        for (int qSize = q.size(); qSize--; ) {
            const Pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; dir++) {
                Pos next = {cur.p, cur.y+dy[dir], cur.x+dx[dir]};
                if (next.outOfBoundary()
                    || map[next.y][next.x] == WALL
                    || visited[next.p][next.y][next.x]) {
                    continue;
                }

                if (cur.p + 1 == map[next.y][next.x] - '0') {
                    next.p++;
                }

                if (next.p == maxCheckPoint && map[next.y][next.x] == END) {
                    return dist;
                }

                visited[next.p][next.y][next.x] = true;
                q.push(next);
            }
        }

        ++dist;
    } while (!q.empty());

    return -1;
}

int main(void) {
    int testCnt;

    scanf(" %d", &testCnt);
    for (int t = 0; t < testCnt; t++) {
        scanf(" %d %d %d", &ySize, &xSize, &maxCheckPoint);
        for (int y = 0; y < ySize; y++) {
            scanf(" %s", map[y]);
        }

        printf("%d\n", bfs());
    }
    return 0;
}
