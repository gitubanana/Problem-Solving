#include <stdio.h>

void hanoi(int from, int to, int by, int cnt) {
    if (cnt == 1) {
        printf("%d %d\n", from, to);
        return;
    }

    hanoi(from, by, to, cnt - 1);
    printf("%d %d\n", from, to);
    hanoi(by, to, from, cnt - 1);
}

int main(void) {
    int cnt;

    scanf(" %d", &cnt);
    printf("%d\n", (1 << cnt) - 1);
    hanoi(1, 3, 2, cnt);
    return 0;
}
