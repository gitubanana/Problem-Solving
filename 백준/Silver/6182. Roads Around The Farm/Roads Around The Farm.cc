#include <iostream>

int diff;

int takeTheFork(int num) {
    int left = num + diff >> 1;
    int right = left - diff;
    if (right <= 0 || left + right != num) {
        return 1;
    }

    return takeTheFork(left) + takeTheFork(right);
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    int num;

    std::cin >> num >> diff;
    std::cout << takeTheFork(num);
    return 0;
}