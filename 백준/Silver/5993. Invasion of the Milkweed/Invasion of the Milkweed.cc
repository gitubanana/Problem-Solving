#include <stdio.h>
#include <cstring>
#include <queue>

enum e_space {
    WALL = '*',
    EMPTY = '.'
};

const int MAX_SIZE = 100;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];

class Pos {
public:
    int y, x;

    inline bool outOfBoundary(void) const {
        return y == -1 || y == ySize
            || x == -1 || x == xSize;
    }
};

int bfs(const Pos &start) {
    std::queue<Pos> q;
    int week = 0;

    q.push(start);
    map[start.y][start.x] = WALL;
    do {
        for (int qSize = q.size(); qSize--; ) {
            const Pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; dir++) {
                const Pos next = {cur.y+dy[dir], cur.x+dx[dir]};
                if (next.outOfBoundary() || map[next.y][next.x] == WALL) {
                    continue;
                }

                map[next.y][next.x] = WALL;
                q.push(next);
            }
        }
    } while (!q.empty() && ++week);
    return week;
}

int main(void) {
    Pos start;

    scanf(" %d %d %d %d", &xSize, &ySize, &start.x, &start.y);
    for (int y = 0; y < ySize; y++) {
        scanf(" %s", map[y]);
    }

    start.x--;
    start.y = ySize - start.y;
    printf("%d\n", bfs(start));
    return 0;
}
