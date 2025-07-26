#include <stdio.h>

const int MAX_SIZE = 1002;
const char LAND = '1';
const char VISITED = '!';
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE];

inline bool outOfBoundary(int y, int x) {
    return !(0 <= y && y < ySize)
            || !(0 <= x && x < xSize);
}

int dfs(int y=0, int x=0) {
    int landCnt = 0;


    map[y][x] = VISITED;
    for (int dir = 0; dir < dirSize; dir++) {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];
        if (outOfBoundary(nextY, nextX)) {
            continue;
        }

        switch (map[nextY][nextX])
        {
        case LAND:
            landCnt++;
            break;
        case VISITED:
            break;
        default:
            landCnt += dfs(nextY, nextX);
        }
    }
    return landCnt;
}

int main(void) {
    fscanf(stdin, " %d %d", &ySize, &xSize);
    for (int y = 1; y <= ySize; y++) {
        fscanf(stdin, " %s", map[y] + 1);
    }

    ySize += 2;
    xSize += 2;
    fprintf(stdout, "%d\n", dfs());
    return 0;
}
