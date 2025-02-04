#include <stdio.h>
#include <queue>

struct t_pos {
    int y, x;

    inline bool operator==(const t_pos &other) const {
        return this->y == other.y && this->x == other.x;
    }
};

const int MAX_SIZE = 1001 + 1;
const int OFFSET = 500;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

bool isPuddle[MAX_SIZE][MAX_SIZE];

inline bool outOfBound(const t_pos &pos) {
    int y = pos.y + OFFSET;
    int x = pos.x + OFFSET;

    return !(0 <= y && y < MAX_SIZE)
            || !(0 <= x && x < MAX_SIZE);
}

bool &getPuddleAt(const t_pos &pos) {
    return isPuddle[pos.y + OFFSET][pos.x + OFFSET];
}

int bfs(const t_pos &start, const t_pos &end) {
    if (start == end) {
        return 0;
    }

    int dist = 0;
    std::queue<t_pos> q;

    getPuddleAt(start) = true;
    q.push(start);
    while (!q.empty()) {
        int qSize = q.size();

        ++dist;
        while (qSize-- > 0) {
            const t_pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; dir++) {
                t_pos next = {cur.y + dy[dir], cur.x + dx[dir]};

                if (outOfBound(next) || getPuddleAt(next)) {
                    continue;
                }

                if (next == end) {
                    return dist;
                }

                getPuddleAt(next) = true;
                q.push(next);
            }
        }
    }
    return -1;
}

int main(void) {
    t_pos start = {0, 0};
    t_pos end;

    int puddleCnt;

    fscanf(stdin, " %d %d %d", &end.y, &end.x, &puddleCnt);
    while (puddleCnt-- > 0) {
        t_pos pos;

        fscanf(stdin, " %d %d", &pos.y, &pos.x);
        getPuddleAt(pos) = true;
    }

    fprintf(stdout, "%d\n", bfs(start, end));
    return 0;
}
