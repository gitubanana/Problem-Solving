#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

enum e_data {
    EMPTY = '0',
    OCCUPIED = '1'
};

enum e_state {
    NONE = 0,
    USING,
    COMPLETED
};

int dataCnt;
int useTime, flushTime;
std::string data;
e_state state = NONE;

void detectUsing(int &t) {
    int used = 0;

    while (data[t] == OCCUPIED) {
        t++;
        used++;
    }

    if (used >= useTime) {
        state = USING;
    }
}

void detectCompleted(int &t) {
    int emptyTime = 0;

    while (t < dataCnt) {
        while (data[t++] == EMPTY) {
            emptyTime++;
            if (emptyTime == flushTime) {
                std::cout << t << '\n';
                return;
            }
        }
        emptyTime = 0;
    }

    std::cout << t + (flushTime - emptyTime) << '\n';
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    bool someonePeed = false;

    std::cin >> useTime >> flushTime >> dataCnt >> data;
    for (int t = 0; t < dataCnt; t++) {
        state = NONE;

        detectUsing(t);
        if (state != USING) {
            continue;
        }

        someonePeed = true;
        detectCompleted(t);
        t--;
    }

    if (!someonePeed) {
        std::cout << "NIKAD" << '\n';
    }
    return (0);
}
