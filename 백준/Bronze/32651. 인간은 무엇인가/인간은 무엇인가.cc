#include <iostream>

void doYouRemember(int num) {
    static const char *MSGS[] = {"No", "Yes"};
    static const int DIVISOR = 2024;
    static const int LIMIT = 1e5;

    throw MSGS[num <= LIMIT && num % DIVISOR == 0];
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    int num;

    scanf(" %d", &num);
    try {
        doYouRemember(num);
    } catch (const char *msg) {
        printf("%s\n", msg);
    }
    return 0;
}