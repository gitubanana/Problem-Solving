#include <iostream>
#include <cmath>

int w, h;

const char *throwMatch(int length) {
    static int maxLength = std::pow(w, 2) + std::pow(h, 2);

    if (maxLength < length * length) {
        throw "NE";
    }
    return "DA";
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    int size;

    std::cin >> size >> w >> h;
    for (int i = 0; i < size; i++) {
        int length;

        std::cin >> length;
        try {
            std::cout << throwMatch(length) << '\n';
        } catch (const char *msg) {
            std::cout << msg << '\n';
        }
    }
    return 0;
}