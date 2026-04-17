#include <stdio.h>
#include <cstring>
#include <queue>

enum e_space {
    WALL = '*',
    EMPTY = '.'
};

const int MAX_SIZE = 750;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];

inline bool outOfBoundary(int y, int x) {
    return y == -1 || y == ySize
        || x == -1 || x == xSize;
}

int dfs(int y, int x) {
    int ret = 1;

    map[y][x] = WALL;
    for (int dir = 0; dir < dirSize; dir++) {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];
    
        if (outOfBoundary(nextY, nextX) || map[nextY][nextX] == WALL) {
            continue;
        }

        ret += dfs(nextY, nextX);
    }
    return ret;
}

int main(void) {
    scanf(" %d %d", &xSize, &ySize);
    for (int y = 0; y < ySize; y++) {
        scanf(" %s", map[y]);
    }

    int ans = 0;

    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            if (map[y][x] == WALL) {
                continue;
            }

            ans = std::max(ans, dfs(y, x));
        }
    }

    printf("%d\n", ans);
    return 0;
}
