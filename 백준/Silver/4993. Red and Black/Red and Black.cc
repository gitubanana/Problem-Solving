#include <stdio.h>

enum e_space {
    EMPTY = '.',
    VISITED = '#',
    START = '@'
};

const int MAX_SIZE = 20;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int cnt;
int ySize, xSize;
char map[MAX_SIZE + 2][MAX_SIZE + 2];

void dfs(int y, int x) {
    if (map[y][x] != EMPTY) {
        return;
    }

    cnt++;
    map[y][x] = VISITED;
    for (int dir = 0; dir < dirSize; dir++) {
        dfs(y+dy[dir], x+dx[dir]);
    }
}

int main(void) {
    while (true) {
        scanf(" %d %d", &xSize, &ySize);
        if (xSize == 0) {
            break;
        }

        int startY = -1, startX;

        for (int y = 1; y <= ySize; y++) {
            scanf(" %s", &map[y][1]);
            if (startY != -1) {
                continue;
            }

            for (int x = 1; x <= xSize; x++) {
                if (map[y][x] == START) {
                    startY = y;
                    startX = x;
                    break;
                }
            }
        }

        for (int x = 1; x <= xSize; x++) {
            map[ySize + 1][x] = VISITED;
        }

        cnt = 0;
        map[startY][startX] = EMPTY;
        dfs(startY, startX);
        printf("%d\n", cnt);
    }
    return 0;
}
