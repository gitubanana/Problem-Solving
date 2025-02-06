#include <stdio.h>
#include <queue>
#include <string.h>
#include <limits.h>

enum e_space {
    EMPTY = '0',
    VILLAGE
};

struct t_pos {
    int y, x;
};

const int MAX_SIZE = 20;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int villageCnt;
int ySize, xSize;
bool visited[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];

inline int min(int a, int b) {
    return a > b ? b : a;
}

inline bool outOfBound(const t_pos &pos) {
    return !(0 <= pos.y && pos.y < ySize)
            || !(0 <= pos.x && pos.x < xSize);
}

int bfs(const t_pos &s1, const t_pos &s2) {
    int sec = 0;
    int poisonCnt = 0;
    std::queue<t_pos> q;

    visited[s1.y][s1.x] = visited[s2.y][s2.x] = true;
    q.push(s1);
    q.push(s2);
    while (!q.empty()) {
        int qSize = q.size();

        ++sec;
        while (qSize-- > 0) {
            const t_pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; dir++) {
                t_pos next = {cur.y + dy[dir], cur.x + dx[dir]};

                if (outOfBound(next) || visited[next.y][next.x]) {
                    continue;
                }

                poisonCnt += (map[next.y][next.x] == VILLAGE);
                if (poisonCnt == villageCnt) {
                    return sec;
                }

                visited[next.y][next.x] = true;
                q.push(next);
            }
        }
    }
    return -1;
}

int main(void) {
    fscanf(stdin, " %d %d", &ySize, &xSize);
    for (int y = 0; y < ySize; y++) {
        fscanf(stdin, " %s", map[y]);

        for (int x = 0; x < xSize; x++) {
            villageCnt += (map[y][x] == VILLAGE);
        }
    }

    int ans = INT_MAX;
    int maxPos = ySize * xSize;
    for (int one = 0; one < maxPos; one++) {
        t_pos s1 = {one / xSize, one % xSize};
        if (map[s1.y][s1.x] == VILLAGE) {
            continue;
        }

        for (int two = one + 1; two < maxPos; two++) {
            t_pos s2 = {two / xSize, two % xSize};
            if (map[s2.y][s2.x] == VILLAGE) {
                continue;
            }

            memset(visited, false, sizeof(visited));
            ans = min(ans, bfs(s1, s2));
        }
    }

    fprintf(stdout, "%d\n", ans);
    return 0;
}
