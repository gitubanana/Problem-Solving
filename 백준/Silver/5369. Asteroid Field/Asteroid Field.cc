#include <stdio.h>
#include <queue>

enum e_space {
    START = 's',
    END = 'd',
    EMPTY = '-',
    ASTEROID = '*'
};

const int MAX_SIZE = 1 << 5;

int size;
char map[MAX_SIZE][MAX_SIZE];

class Pos {
public:
    static inline const int dy[] = {-1, 1, 0, 0};
    static inline const int dx[] = {0, 0, -1, 1};
    static inline const int dirSize = sizeof(dy) / sizeof(dy[0]);

    int y, x;

    inline bool outOfBound(void) const {
        return y < 0 || y >= size
            || x < 0 || x >= size;
    }
};

int bfs(const Pos &start) {
    std::queue<Pos> q;
    int dist = 1;

    map[start.y][start.x] = ASTEROID;
    q.push(start);
    do {
        for (int qSize = q.size(); qSize--; ) {
            const Pos cur = q.front();
            q.pop();
    
            for (int dir = 0; dir < Pos::dirSize; dir++) {
                const Pos next = {cur.y+Pos::dy[dir], cur.x+Pos::dx[dir]};
                if (next.outOfBound() || map[next.y][next.x] == ASTEROID) {
                    continue;
                }
    
                char &nextSpace = map[next.y][next.x];
                if (nextSpace == END) {
                    return dist;
                }
    
                nextSpace = ASTEROID;
                q.push(next);
            }
        }
        
    } while (!q.empty() && ++dist);

    return -1;
}


int main() {
    int testCnt;

    scanf(" %d", &testCnt);
    for (int t = 0; t < testCnt; t++) {
        Pos start = {-1};

        scanf(" %d", &size);
        for (int y = 0; y < size; y++) {
            scanf(" %s", map[y]);
            if (start.y != -1) {
                continue;
            }

            for (int x = 0; x < size; x++) {
                if (map[y][x] == START) {
                    start = {y, x};
                    break;
                }
            }
        }

        printf("%d\n", bfs(start));
    }
    return 0;
}