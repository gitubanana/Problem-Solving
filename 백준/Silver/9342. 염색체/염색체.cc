#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

// (A+B+C+D+E+F+lambda)A^+F^+C^+(A+B+C+D+E+F+lambda)

std::string str;

void BCDEF(int &idx) {
    const char &ch = str[idx];

    for (int i = 0; __func__[i]; i++) {
        if (ch == __func__[i]) {
            idx++;
            return;
        }
    }
}

void ABCDEF(int &idx) {
    const char &ch = str[idx];

    for (int i = 0; __func__[i]; i++) {
        if (ch == __func__[i]) {
            idx++;
            return;
        }
    }
}

bool atLeastOne(char check, int &idx) {
    if (str[idx] != check) {
        return false;
    }

    while (str[++idx] == check) {
        ;
    }
    return true;
}

bool isAccepted() {
    int idx = 0;

    BCDEF(idx);
    if (!atLeastOne('A', idx)
        || !atLeastOne('F', idx)
        || !atLeastOne('C', idx)) {
        return false;
    }
    ABCDEF(idx);

    return idx == str.size();
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    const char *msg[] = {"Good", "Infected!"};

    std::cin >> testCnt;
    while (testCnt-- > 0) {
        std::cin >> str;
        std::cout << msg[isAccepted()] << '\n';
    }
    return (0);
}
