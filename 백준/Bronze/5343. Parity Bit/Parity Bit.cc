#include <stdio.h>

const int MAX_LENGTH = 64 + 1;

int main(void) {
    int testCnt;
    char bits[MAX_LENGTH];

    fscanf(stdin, " %d", &testCnt);
    while (testCnt-- > 0) {        
        int errorCnt = 0;

        fscanf(stdin, " %s", bits);
        for (int s = 0; bits[s]; s += 8) {
            int oneCnt = 0;

            for (int i = 0; i < 8; i++) {
                oneCnt += (bits[s + i] == '1');
            }
            errorCnt += (oneCnt & 1 == 1);
        }

        fprintf(stdout, "%d\n", errorCnt);
    }
    return 0;
}
