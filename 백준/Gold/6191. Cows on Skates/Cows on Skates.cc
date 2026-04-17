#include <stdio.h>
#include <queue>

enum e_space {
    EMPTY = '.',
    WALL = '*'
};

const int MAX_Y = 113;
const int MAX_X = 77;
const int STOP_PREV = __INT32_MAX__;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

struct Pos {
    int y, x;
};

int ySize, xSize;
int prevs[MAX_Y][MAX_X];
char map[MAX_Y][MAX_X + 1];

inline bool outOfRange(const Pos &pos) {
    return (pos.y < 0 || pos.y >= ySize)
            || (pos.x < 0 || pos.x >= xSize);
}

void bfs(const Pos &start) {
    std::queue<Pos> q;

    prevs[start.y][start.x] = STOP_PREV;
    q.push(start);
    while (!q.empty()) {
        const Pos cur = q.front();
        q.pop();

        for (int dir = 0; dir < dirSize; dir++) {
            Pos next = {cur.y + dy[dir], cur.x + dx[dir]};
            if (outOfRange(next)
                || map[next.y][next.x] == WALL
                || prevs[next.y][next.x]) {
                    continue;
            }

            prevs[next.y][next.x] = cur.y * xSize + cur.x;
            q.push(next);
        }
    }
}

void printPath(const Pos &start) {
    Pos cur = start;

    while (true) {
        int &prev = prevs[cur.y][cur.x];

        printf(" %d %d\n", cur.y + 1, cur.x + 1);
        if (prev == STOP_PREV) {
            break;
        }

        cur.y = prev / xSize;
        cur.x = prev % xSize;
    }
}

int main(void) {
    scanf(" %d %d", &ySize, &xSize);
    for (int y = 0; y < ySize; y++) {
        scanf(" %s", map[y]);
    }

    bfs({ySize - 1, xSize - 1});
    printPath({0, 0});
    return 0;
}
