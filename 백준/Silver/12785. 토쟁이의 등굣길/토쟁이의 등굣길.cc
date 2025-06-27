#include <stdio.h>

class Pos {
public:
    int y, x;

    Pos(void) {
        scanf(" %d %d", &x, &y);
        --x, --y;
    }

    Pos(int y, int x) : y(y), x(x) { }

    inline bool operator==(const Pos &other) const {
        return this->y == other.y && this->x == other.x;
    }

    inline bool outOfRange(const Pos &end) const {
        return this->y > end.y || this->x > end.x;
    }
};

const int MAX_SIZE = 200;
const int DIVISOR = 1e6 + 7;
const int dy[] = {1, 0};
const int dx[] = {0, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int dp[MAX_SIZE][MAX_SIZE];

int dfs(const Pos &cur, const Pos &end) {
    if (cur == end) {
        return 1;
    }

    int &curDp = dp[cur.y][cur.x];
    if (curDp != 0) {
        return curDp;
    }

    for (int dir = 0; dir < dirSize; dir++) {
        Pos next(cur.y + dy[dir], cur.x + dx[dir]);
        if (next.outOfRange(end)) {
            continue;
        }

        curDp += dfs(next, end);
        curDp %= DIVISOR;
    }
    return curDp;
}

int main(void) {
    Pos end;
    Pos via;
    Pos start(0, 0);

    printf("%lld\n", static_cast<long long>(dfs(start, via)) * dfs(via, end) % DIVISOR);
    return 0;
}
