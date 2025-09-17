#include <stdio.h>
#include <vector>
#include <queue>

const int MAX_NUMBER = 1e8;

std::vector<int> fibo;

void makeFibo() {
    int elem;

    fibo.push_back(0);
    fibo.push_back(1);
    do {
        elem = fibo[fibo.size() - 1] + fibo[fibo.size() - 2];
        fibo.push_back(elem);
    } while (elem <= MAX_NUMBER);
}

int main(void) {
    makeFibo();
    while (true) {
        int size, filler, maxNum;

        scanf(" %d %d %d", &size, &filler, &maxNum);
        if (size == 0) {
            break;
        }

        int ans = 0;
        std::priority_queue<int> pq;
        for (int i = 0; i < size; i++) {
            int elem;
            scanf(" %d", &elem);

            int diff = *std::lower_bound(fibo.begin(), fibo.end(), elem) - elem;
            if (diff == 0) {
                ans++;
            } else {
                pq.push(-diff);
            }
        }

        while (!pq.empty()) {
            int use = -pq.top();
            pq.pop();

            filler -= use;
            if (filler < 0) {
                break;
            }

            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
