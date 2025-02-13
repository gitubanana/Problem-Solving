#include <stdio.h>

const int MAX_SIZE = 70 + 1;
const int ALPHA_CNT = 26;

char str[MAX_SIZE];
int cnt[ALPHA_CNT];

int getAns() {
    int bits = 0;

    for (int i = 0; i < ALPHA_CNT; i++) {
        if (cnt[i] == 0) {
            continue;
        }

        bits |= (1 << (cnt[i] & 1));
    }

    return bits - 1;
}

int main(void) {
    fscanf(stdin, " %s", str);
    for (int i = 0; str[i]; i++) {
        ++cnt[str[i] - 'a'];
    }

    fprintf(stdout, "%d\n", getAns());
    return 0;
}
