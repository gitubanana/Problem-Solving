#include <stdio.h>

const int MAX_SIZE = 50;

int cnts[MAX_SIZE+1];

int main() {
    int size;

    scanf(" %d", &size);
    while (size--) {
        int num;

        scanf(" %d", &num);
        cnts[num]++;
    }

    int ans = 0;
    int prev = 1;

    for (int i = 1; i <= MAX_SIZE; i++) {
        if (cnts[i] == 0) {
            break;
        }

        prev *= cnts[i];
        ans += prev;
    }

    printf("%d\n", ans);
    return 0;
}