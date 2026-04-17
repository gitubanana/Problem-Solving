#include <stdio.h>
#include <cctype>
#include <queue>
#define IS_VISITED(a) !std::isdigit(a)

const int MAX_SIZE = 5e2;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];

class Pos {
public:
    int y, x;

    inline bool operator==(const Pos &other) const {
        return this->y == other.y && this->x == other.x;
    }

    inline bool outOfBoundary(void) const {
        return y < 0 || y >= ySize
            || x < 0 || x >= xSize;
    }
};

int bfs(const Pos &start={0, 0}, const Pos &end={ySize-1, xSize-1}) {
    int dist = 1;
    std::queue<Pos> q;

    map[start.y][start.x] -= '0';
    q.push(start);
    do {
        for (int qSize = q.size(); qSize--; ) {
            const Pos cur = q.front();
            const int &move = map[cur.y][cur.x];
            q.pop();

            for (int dir = 0; dir < dirSize; dir++) {
                const Pos next = {cur.y + dy[dir]*move, cur.x + dx[dir]*move};
                if (next.outOfBoundary() || IS_VISITED(map[next.y][next.x])) {
                    continue;
                }

                if (next == end) {
                    return dist;
                }

                map[next.y][next.x] -= '0';
                q.push(next);
            }
        }

    } while (!q.empty() && ++dist);

    return -1;
}

int main(void) {
    scanf(" %d %d", &ySize, &xSize);
    for (int y = 0; y < ySize; y++) {
        scanf(" %s", map[y]);
    }

    int dist = bfs();
    if (dist == -1) {
        printf("IMPOSSIBLE\n");
    } else {
        printf("%d\n", dist);
    }
    return 0;
}
