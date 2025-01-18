#include <iostream>
#include <unordered_set>

const int ROOT = 1;
const int MAX_V = 1 << 20;

int lastLand;
bool soldout[MAX_V];

int getAns(int wantLand) {
    int stop = -1;
    int cur = wantLand;

    while (cur > 0) {
        if (soldout[cur]) {
            stop = cur;
        }

        cur /= 2;
    }

    if (stop == -1) {
        soldout[wantLand] = true;
        return 0;
    }

    return stop;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int duckCnt;

    std::cin >> lastLand >> duckCnt;
    while (duckCnt-- > 0) {
        int wantLand;

        std::cin >> wantLand;
        std::cout << getAns(wantLand) << '\n';
    }
    return 0;
}
