#include <stdio.h>
#include <queue>

const int SIZE = 8;
const int dy[] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

bool visited[SIZE][SIZE];

class Pos {
public:
    int y, x;

    inline bool outOfBoard(void) const {
        return y < 0 || y >= SIZE
            || x < 0 || x >= SIZE;
    }

    inline bool operator==(const Pos &other) const {
        return this->y == other.y && this->x == other.x;
    }
};

int bfs(const Pos &start, const Pos &end) {
    if (start == end) {
        return 0;
    }

    std::queue<Pos> q;
    int dist = 1;

    visited[start.y][start.x] = true;
    q.push(start);
    do {
        for (int qSize = q.size(); qSize--; ) {
            const Pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; dir++) {
                const Pos next = {cur.y+dy[dir], cur.x+dx[dir]};
                if (next.outOfBoard() || visited[next.y][next.x]) {
                    continue;
                }

                if (next == end) {
                    return dist;
                }

                visited[next.y][next.x] = true;
                q.push(next);
            }
        }
    } while (!q.empty() && ++dist);
    return -1;
}

int main(void) {
    char str[3];

    scanf(" %s", str);
    Pos start = {SIZE - (str[1] - '0'), str[0] - 'a'};

    scanf(" %s", str);
    Pos end = {SIZE - (str[1] - '0'), str[0] - 'a'};

    printf("%d\n", bfs(start, end));
    return 0;
}
