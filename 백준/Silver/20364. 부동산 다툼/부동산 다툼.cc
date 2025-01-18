#include <iostream>
#include <unordered_set>

const int ROOT = 1;

int lastLand;
std::unordered_set<int> soldLands;

int getAns(int wantLand) {
    int stop = -1;
    int cur = wantLand;

    while (cur > 0) {
        if (soldLands.find(cur) != soldLands.end()) {
            stop = cur;
        }

        cur /= 2;
    }

    if (stop == -1) {
        soldLands.insert(wantLand);
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
