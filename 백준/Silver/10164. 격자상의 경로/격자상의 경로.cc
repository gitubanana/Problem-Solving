#include <iostream>
#include <vector>

struct t_pos {
    int y, x;
};

long fact(int n) {
    long ret = 1;

    while (n > 1) {
        ret *= n;
        --n;
    }
    return ret;
}

long countWays(std::vector<t_pos> &positions) {
    long ways = 1;

    for (int i = 1; i < positions.size(); i++) {
        const t_pos &prev = positions[i - 1];
        const t_pos &cur = positions[i];
        const int yCnt = cur.y - prev.y;
        const int xCnt = cur.x - prev.x;

        ways *= fact(yCnt + xCnt) / (fact(yCnt) * fact(xCnt));
    }
    return ways;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int ySize, xSize, via;
    std::vector<t_pos> positions;

    std::cin >> ySize >> xSize >> via;
    --via;

    positions.push_back({0, 0});
    if (via > 0) {
        positions.push_back({via / xSize, via % xSize});
    }
    positions.push_back({ySize - 1, xSize - 1});

    std::cout << countWays(positions) << '\n';
    return 0;
}
