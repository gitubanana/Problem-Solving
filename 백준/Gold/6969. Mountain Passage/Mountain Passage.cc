#include <stdio.h>
#include <limits.h>
#include <deque>

struct t_pos {
    int y, x;

    inline bool operator==(const t_pos &other) const {
        return this->y == other.y && this->x == other.x;
    }
};

const int MAX_SIZE = 25;
const t_pos START = {0, 0};
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size;
int count[MAX_SIZE][MAX_SIZE];
int elevation[MAX_SIZE][MAX_SIZE];

inline bool outOfBound(const t_pos &pos) {
    return !(0 <= pos.y && pos.y < size)
            || !(0 <= pos.x && pos.x < size);
}

inline int abs(int a, int b) {
    int diff = a - b;

    if (diff >= 0) {
        return diff;
    }

    return -diff;
}

int bfs01() {
    if (size == 1) {
        return 0;
    }

    std::deque<t_pos> deq;
    t_pos end = {size - 1, size - 1};
    const int &firstHeight = elevation[START.y][START.x];

    count[START.y][START.x] = 0;
    deq.push_back(START);
    while (!deq.empty()) {
        const t_pos cur = deq.front();
        const int &curCount = count[cur.y][cur.x];
        const int &curHeight = elevation[cur.y][cur.x];
        deq.pop_front();

        for (int dir = 0; dir < dirSize; dir++) {
            t_pos next = {cur.y + dy[dir], cur.x + dx[dir]};
            if (outOfBound(next)) {
                continue;
            }

            const int &nextHeight = elevation[next.y][next.x];
            if (abs(curHeight, nextHeight) > 2) {
                continue;
            }

            bool pushBack = false;
            int cmpCount = curCount;
            if (curHeight > firstHeight || nextHeight > firstHeight) {
                pushBack = true;
                cmpCount++;
            }

            int &nextCount = count[next.y][next.x];
            if (nextCount <= cmpCount) {
                continue;
            }

            nextCount = cmpCount;
            if (next == end) {
                continue;
            }

            if (pushBack) {
                deq.push_back(next);
            } else {
                deq.push_front(next);
            }
        }
    }
    return count[end.y][end.x];
}

int main(void) {
    int testCnt;

    fscanf(stdin, " %d", &testCnt);
    for (int i = 0; i < testCnt; i++) {
        fscanf(stdin, " %d", &size);

        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                fscanf(stdin, " %d", &elevation[y][x]);
                count[y][x] = INT_MAX;
            }
        }

        int ans = bfs01();
        if (ans == INT_MAX) {
            fprintf(stdout, "CANNOT MAKE THE TRIP\n");
        } else {
            fprintf(stdout, "%d\n", ans);
        }
        fprintf(stdout, "\n");
    }
    return 0;
}
