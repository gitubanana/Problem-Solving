#include <stdio.h>
#include <string.h>
#include <algorithm>

enum e_bit {
    ZERO = '0',
    ONE
};

enum e_parity {
    ODD_PARITY = 'o',
    EVEN_PARITY = 'e'
};

const int MAX_LENGTH = 31 + 1;
const char EOF_ = '#';

int main(void) {
    char bits[MAX_LENGTH];

    while (true) {
        fscanf(stdin, " %s", bits);
        int len = strlen(bits);
        char &lastCh = bits[len - 1];
        if (lastCh == EOF_) {
            break;
        }

        int oneCnt = std::count(bits, bits + len, ONE);

        if (lastCh == ODD_PARITY) {
            lastCh = (oneCnt & 1) ? ZERO : ONE;
        } else {
            lastCh = (oneCnt & 1) ? ONE : ZERO;
        }

        fprintf(stdout, "%s\n", bits);
    }
    return 0;
}
