#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 40

enum e_space {
    START = 'A',
    WALL = '#',
    CAN_GO = '.'
};

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];

int dfs(int y, int x) {
    if (!(0 <= y && y < ySize)
        || !(0 <= x && x < xSize)
        || map[y][x] != CAN_GO)
    {
        return 0;
    }

    int ret = 1;

    map[y][x] = WALL; 
    for (int dir = 0; dir < dirSize; dir++) {
        ret += dfs(y + dy[dir], x + dx[dir]);
    }
    return ret;
}

int main(void) {
    while (true) {
        scanf(" %d %d", &xSize, &ySize);
        if (xSize == 0) {
            break;
        }

        int startY = -1, startX;

        for (int y = 0; y < ySize; y++) {
            for (int x = 0; x < xSize; x++) {
                scanf(" %c", &map[y][x]);
                if (map[y][x] == START) {
                    map[y][x] = CAN_GO;
                    startY = y;
                    startX = x;
                }
            }
        }

        printf("%d\n", dfs(startY, startX));
    }
    return 0;
}
