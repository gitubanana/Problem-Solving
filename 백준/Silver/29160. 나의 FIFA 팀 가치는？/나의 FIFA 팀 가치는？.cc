#include <iostream>
#include <queue>

const int POSITION_COUNT = 11;

std::priority_queue<int> pqByPos[POSITION_COUNT + 1];

void popAndDecrease(int pos) {
    std::priority_queue<int> &pq = pqByPos[pos];
    int max = pq.top() - 1;

    pq.pop();
    if (max == 0) {
        return;
    }

    pq.push(max);
}

int getAns() {
    int ans = 0;

    for (int pos = 1; pos <= POSITION_COUNT; pos++) {
        std::priority_queue<int> &pq = pqByPos[pos];
        if (pq.empty()) {
            continue;
        }

        ans += pq.top();
    }
    return ans;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int playerCount;
    int yearCount;

    std::cin >> playerCount >> yearCount;
    while (playerCount-- > 0) {
        int pos, value;

        std::cin >> pos >> value;
        pqByPos[pos].push(value);
    }

    for (int pos = 1; pos <= POSITION_COUNT; pos++) {
        for (int y = 0; y < yearCount; y++) {
            if (pqByPos[pos].empty()) {
                break;
            }
            popAndDecrease(pos);
        }
    }

    std::cout << getAns() << '\n';
	return 0;
}