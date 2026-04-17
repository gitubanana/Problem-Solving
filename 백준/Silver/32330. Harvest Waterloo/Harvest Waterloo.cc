#include <stdio.h>

enum e_space {
    HAY = '*'
};

const int MAX_SIZE = 317;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);
const char *PUMPKINS = "SML";
const int VALUES[] = {1, 5, 10};

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];

class Pos {
public:
    int y, x;

    inline bool outOfBoundary(void) const {
        return y == -1 || y == ySize
            || x == -1 || x == xSize;
    }
};

int getPumpkinValue(const char &space) {
    for (int i = 0; PUMPKINS[i]; i++) {
        if (PUMPKINS[i] == space) {
            return VALUES[i];
        }
    }
    return -1;
} 

int dfs(const Pos &cur) {
    char &space = map[cur.y][cur.x];
    if (space == HAY) {
        return 0;
    }

    int ret = getPumpkinValue(space);

    space = HAY;
    for (int dir = 0; dir < dirSize; dir++) {
        const Pos next = {cur.y+dy[dir], cur.x+dx[dir]};
        if (next.outOfBoundary()) {
            continue;
        }

        ret += dfs(next);
    }
    return ret;
}

int main(void) {
    scanf(" %d %d", &ySize, &xSize);
    for (int y = 0; y < ySize; y++) {
        scanf(" %s", map[y]);
    }

    Pos start;

    scanf(" %d %d", &start.y, &start.x);
    printf("%d\n", dfs(start));
    return 0;
}
