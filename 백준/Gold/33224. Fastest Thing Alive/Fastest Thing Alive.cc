#include <stdio.h>

enum e_space {
    EMPTY = '_',
    SPIKE = '*'
};

const char *move = "_RFL";
const int dy[] = {0, -1, -1, -1};
const int dx[] = {0, -1, 0, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);
const int MAX_SIZE = 1e3;
const int NO_DIR = 0;
const int START = -1;

int ySize, xSize;
int dirs[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];

inline bool outOfBoundary(int y, int x) {
    return y < 0 || y >= ySize
        || x < 0 || x >= xSize;
}

void simulation(void) {
    for (int x = 0; x < xSize; x++) {
        dirs[0][x] = START;
    }

    for (int y = 1; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            if (map[y][x] == SPIKE) {
                continue;
            }

            for (int dir = 1; dir < dirSize; dir++) {
                int prevY = y + dy[dir];
                int prevX = x + dx[dir];
                if (outOfBoundary(prevY, prevX)
                    || map[prevY][prevX] == SPIKE
                    || dirs[prevY][prevX] == NO_DIR) {
                    continue;
                }

                dirs[y][x] = dir;
                break;
            }
        }
    }
}

void backTrack(void) {
    int curY = ySize - 1;
    int curX = START;

    for (int x = 0; x < xSize; x++) {
        if (dirs[curY][x] != NO_DIR) {
            curX = x;
            break;
        }
    }

    if (curX == START) {
        printf("impossible\n");
        return;
    }

    char *path = new char[ySize];
    int idx = ySize;

    path[--idx] = 0;
    do {
        const int &dir = dirs[curY][curX];

        path[--idx] = move[dir];
        curY += dy[dir];
        curX += dx[dir];
    } while (curY != 0);

    printf("%d\n%s\n", curX + 1, path);
    delete[] path;
}

int main(void) {
    scanf(" %d %d", &ySize, &xSize);
    for (int y = 0; y < ySize; y++) {
        scanf(" %s", map[y]);
    }

    simulation();
    backTrack();
    return 0;
}
