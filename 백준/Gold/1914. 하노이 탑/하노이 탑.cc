#include <stdio.h>
#include <stdint.h>

using ll = __int128_t;

void hanoi(int from, int to, int by, int cnt) {
    if (cnt == 1) {
        printf("%d %d\n", from, to);
        return;
    }

    hanoi(from, by, to, cnt - 1);
    printf("%d %d\n", from, to);
    hanoi(by, to, from, cnt - 1);
}

void printNumber(ll num) {
    if (num == 0) {
        return;
    }

    printNumber(num / 10);
    printf("%c", '0' + static_cast<int>(num % 10));
}

int main(void) {
    int cnt;

    scanf(" %d", &cnt);
    printNumber((static_cast<ll>(1) << cnt) - 1);
    printf("\n");
    if (cnt <= 20) {
        hanoi(1, 3, 2, cnt);
    }
    return 0;
}
