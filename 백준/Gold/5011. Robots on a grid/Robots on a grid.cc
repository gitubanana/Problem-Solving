#include <stdio.h>
#include <string.h>

enum e_space {
    EMPTY = '.',
    WALL = '#'
};

typedef long long ll;

const int MAX_SIZE = 1 << 10;
const int INIT_VALUE = -1;

int size;
ll dp[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];

class Pos {
public:
    int y, x;

    inline bool operator==(const Pos &other) const {
        return this->y == other.y && this->x == other.x;
    }

    inline bool outOfBoundary(void) const {
        return y < 0 || y >= size
            || x < 0 || x >= size;
    }
};

namespace DIR2 {
    int dy[] = {1, 0};
    int dx[] = {0, 1};
    int dirSize = sizeof(dy) / sizeof(dy[0]);
    int MODULO = __INT_MAX__;

    ll dfs(const Pos &cur={0, 0}, const Pos &end={size-1,size-1}) {
        if (cur == end) {
            return dp[end.y][end.x] = 1;
        }
    
        ll &curDp = dp[cur.y][cur.x];
        if (curDp != INIT_VALUE) {
            return curDp;
        }
    
        curDp = 0;
        for (int dir = 0; dir < dirSize; dir++) {
            const Pos next = {cur.y+dy[dir], cur.x+dx[dir]};
            if (next.outOfBoundary() || map[next.y][next.x] == WALL) {
                continue;
            }
    
            curDp += dfs(next, end);
            curDp %= MODULO;
        }
        return curDp;
    }
}

namespace DIR4 {
    int dy[] = {1, 0, -1, 0};
    int dx[] = {0, 1, 0, -1};
    int dirSize = sizeof(dy) / sizeof(dy[0]);

    bool dfs(const Pos &cur={0, 0}, const Pos &end={size-1,size-1}) {
        if (cur == end) {
            return true;
        }

        map[cur.y][cur.x] = WALL;
        for (int dir = 0; dir < dirSize; dir++) {
            const Pos next = {cur.y+dy[dir], cur.x+dx[dir]};
            if (next.outOfBoundary() || map[next.y][next.x] == WALL) {
                continue;
            }

            if (dfs(next, end)) {
                return true;
            }
        }
        return false;
    }
}

int main(void) {
    scanf(" %d", &size);
    for (int y = 0; y < size; y++) {
        scanf(" %s", map[y]);
    }
    memset(dp, INIT_VALUE, sizeof(dp));

    ll pathCnt = DIR2::dfs();
    if (dp[size-1][size-1] != INIT_VALUE) {
        printf("%lld\n", pathCnt);
    } else {
        printf("%s\n", DIR4::dfs() ? "THE GAME IS A LIE" : "INCONCEIVABLE");
    }
    return 0;
}
