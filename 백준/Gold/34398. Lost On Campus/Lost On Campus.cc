#include <stdio.h>
#include <queue>

enum e_space {
    FLOOR = '.',
    WALL = '#',
    DOOR = 'D',
    EXIT = 'E',
    START = '*'
};

class Pos {
public:
    int y, x;
};

const int INF = 1e9;
const int MAX_SIZE = 100;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int cnt[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];

int bfs01(void) {
    int ans = INF;
    std::deque<Pos> q;

    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            if (map[y][x] == START) {
                q.push_back({y, x});
                continue;
            }

            cnt[y][x] = INF;
        }
    }

    while (!q.empty()) {
        const Pos cur = q.front();
        const int &curCnt = cnt[cur.y][cur.x];
        q.pop_front();

        for (int dir = 0; dir < dirSize; dir++) {
            const Pos next = {cur.y+dy[dir], cur.x+dx[dir]};
            const char &nextSpace = map[next.y][next.x];
            if (nextSpace == WALL) {
                continue;
            }

            bool isDoor = (nextSpace == DOOR);
            int &cmpCnt = cnt[next.y][next.x];
            int nextCnt = curCnt + isDoor;
            if (cmpCnt <= nextCnt) {
                continue;
            }

            cmpCnt = nextCnt;
            if (isDoor) {
                q.push_back(next);
            } else if (nextSpace == EXIT) {
                ans = std::min(ans, nextCnt);
            } else {
                q.push_front(next);
            }
        }
    }
    return ans;
}

int main(void) {
    scanf(" %d %d", &xSize, &ySize);
    for (int y = 0; y < ySize; y++) {
        scanf(" %s", map[y]);
    }

    int ans = bfs01();
    if (ans == INF) {
        printf("NOT POSSIBLE\n");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}
