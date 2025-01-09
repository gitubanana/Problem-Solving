#include <iostream>
#include <vector>

const int SIZE = 26 + 26;
const int LOWER_PLUS = 26;

bool reachable[SIZE][SIZE];

int toIndex(char ch) {
    if (std::isupper(ch)) {
        return ch - 'A';
    }
    return ch - 'a' + LOWER_PLUS;
}

char toChar(int index) {
    if (index >= LOWER_PLUS) {
        return 'a' + (index - LOWER_PLUS);
    }
    return 'A' + index;
}

void warshall() {
    for (int mid = 0; mid < SIZE; mid++) {
        for (int from = 0; from < SIZE; from++) {
            if (!reachable[from][mid]) {
                continue;
            }

            for (int to = 0; to < SIZE; to++) {
                reachable[from][to] |= reachable[mid][to];
            }
        }
    }
}

void getAns(std::vector<std::string> &ans) {
    for (int from = 0; from < SIZE; from++) {
        for (int to = 0; to < SIZE; to++) {
            if (!reachable[from][to] || from == to) {
                continue;
            }

            std::string str;

            str.push_back(toChar(from));
            str.push_back(toChar(to));
            ans.push_back(str);
        }
    }
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;
    char from, to;
    std::string arrow;

    std::cin >> eCnt;
    while (eCnt-- > 0) {
        std::cin >> from >> arrow >> to;
        reachable[toIndex(from)][toIndex(to)] = true;
    }

    warshall();

    std::vector<std::string> ans;

    getAns(ans);
    std::cout << ans.size() << '\n';
    for (const std::string &cur : ans) {
        std::cout << cur[0] << " => " << cur[1] << '\n';
    }
    return (0);
}
