#include <stdio.h>
#include <queue>

enum e_space {
    EMPTY = '0',
    WALL,
    START = 'S'
};

class Pos {
public:
    int y, x;
};

const int INF = 1e9;
const int MAX_SIZE = 100;
const char *DIR_BLOCK = "DURL";
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize, limitTime;
char map[MAX_SIZE][MAX_SIZE + 1];

inline bool escaped(const Pos &pos) {
    return (pos.y < 0 || pos.y >= ySize)
            || (pos.x < 0 || pos.x >= xSize);
}

inline bool canPassDirBlock(char space, int dir) {
    int i = 0;

    for (int i = 0; DIR_BLOCK[i]; i++) {
        if (space == DIR_BLOCK[i]) {
            return i == dir;
        }
    }
    return true;
}

int bfs(const Pos &start) {
    int curTime = 0;
    std::queue<Pos> q;

    map[start.y][start.x] = WALL;
    q.push(start);
    do {
        for (int qSize = q.size(); qSize--; ) {
            const Pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; dir++) {
                const Pos next = {cur.y+dy[dir], cur.x+dx[dir]};
                if (escaped(next)) {
                    return curTime;
                }

                char &nextSpace = map[next.y][next.x];
                if (nextSpace == WALL) {
                    continue;
                }

                if (canPassDirBlock(nextSpace, dir)) {
                    nextSpace = WALL;
                    q.push(next);
                }
            }
        }
    } while (!q.empty() && ++curTime <= limitTime);

    return INF;
}

int main(void) {
    Pos start = {-1};

    scanf(" %d %d %d", &limitTime, &ySize, &xSize);
    for (int y = 0; y < ySize; y++) {
        scanf(" %s", map[y]);
        if (start.y != -1) {
            continue;
        }

        for (int x = 0; x < xSize; x++) {
            if (map[y][x] == START) {
                start = {y, x};
                break;
            }
        }
    }

    int ans = bfs(start);
    if (ans == INF) {
        printf("NOT POSSIBLE\n");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}
