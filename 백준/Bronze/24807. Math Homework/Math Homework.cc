#include <iostream>

const int SIZE = 3;

int goal;
bool hasAnswer;
int legs[SIZE];
int cnt[SIZE];

void backTracking(int sum=0, int depth=0) {
    if (depth == SIZE) {
        if (sum == goal) {
            hasAnswer = true;
            for (int i = 0; i < SIZE; i++) {
                std::cout << cnt[i] << ' ';
            }
            std::cout << '\n';
        }
        return;
    }

    int &cur = cnt[depth];

    cur = 0;
    do {
        backTracking(sum, depth+1);
        cur++;
        sum += legs[depth];
    } while (sum <= goal);
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < SIZE; i++) {
        std::cin >> legs[i];
    }
    std::cin >> goal;

    backTracking();
    if (!hasAnswer) {
        std::cout << "impossible" << '\n';
    }
    return 0;
}