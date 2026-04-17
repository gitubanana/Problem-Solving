#include <iostream>
#include <cstring>
#include <queue>

enum e_space {
    EMPTY = 0,
    WHITE = 'W',
    BLACK = 'B',
    VISITED = '!'
};

const int MAX_SIZE = 19;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);
const char COLORS[] = {BLACK, WHITE, '\0'};

int size;
int scores[2];
char map[MAX_SIZE][MAX_SIZE];

class Pos {
public:
    int y, x;

    inline bool outOfBoundary(void) const {
        return y == -1 || y == size
            || x == -1 || x == size;
    }
};

inline std::istream &operator>>(std::istream &in, Pos &pos) {
    in >> pos.y >> pos.x;
    --pos.y, --pos.x;
    return in;
}

inline int indexOf(const char &space) {
    for (int i = 0; COLORS[i]; i++) {
        if (space == COLORS[i]) {
            return i;
        }
    }
    throw std::exception();
    return -1;
}

void bfs(const Pos &start) {
    std::queue<Pos> q;
    int score = 1;
    int surrounded = 0;

    map[start.y][start.x] = VISITED;
    q.push(start);
    do {
        const Pos cur = q.front();
        q.pop();

        for (int dir = 0; dir < dirSize; dir++) {
            const Pos next = {cur.y+dy[dir], cur.x+dx[dir]};
            if (next.outOfBoundary() || map[next.y][next.x] == VISITED) {
                continue;
            }

            char &space = map[next.y][next.x];
            if (space != EMPTY) {
                surrounded |= (1 << indexOf(space));
                continue;
            }

            space = VISITED;
            q.push(next);
            score++;
        }
    } while (!q.empty());

    for (int i = 0; COLORS[i]; i++) {
        if (surrounded == (1 << i)) {
            scores[i] += score;
            break;
        }
    }
}

void printAns(void) {
    memset(scores, 0, sizeof(scores));
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (map[y][x] != EMPTY) {
                continue;
            }
            
            bfs({y, x});
        }
    }

    if (scores[0] == scores[1]) {
        printf("Draw\n");
        return;
    }

    if (scores[0] > scores[1]) {
        printf("Black wins by %d\n", scores[0] - scores[1]);
        return;
    }

    printf("White wins by %d\n", scores[1] - scores[0]);
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    while (true) {
        Pos pos;
        int cnt[2];

        std::cin >> size;
        if (size == 0) {
            break;
        }

        std::cin >> cnt[0] >> cnt[1];
        memset(map, EMPTY, sizeof(map));
        for (int i = 0; COLORS[i]; i++) {
            while (cnt[i]--) {
                std::cin >> pos;
                map[pos.y][pos.x] = COLORS[i];
            }
        }

        printAns();    
    }
    return 0;
}
