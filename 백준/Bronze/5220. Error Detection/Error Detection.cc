#include <stdio.h>
#include <string>

const int BIT_COUNT = 16;
const char *msg[] = {"Corrupt", "Valid"};

int main(void) {
    int testCnt;
    std::string result;

    fscanf(stdin, " %d", &testCnt);
    for (int t = 0; t < testCnt; t++) {
        int num, cmpParity;
        fscanf(stdin, " %d %d", &num, &cmpParity);

        int parity = 0;
        for (int i = 0; i < BIT_COUNT; i++) {
            parity ^= (num >> i) & 1;
        }

        result.append(msg[cmpParity == parity]).append("\n");
    }

    fprintf(stdout, "%s", result.c_str());
    return 0;
}
