#include <stdio.h>

enum e_type {
    IP_TO_NUM = 1,
    NUM_TO_IP
};

void printNum() {
    int a, b, c, d, e, f, g, h;
    fscanf(stdin, " %d.%d.%d.%d.%d.%d.%d.%d", &a, &b, &c, &d, &e, &f, &g, &h);

    unsigned long long num = 0;

    num |= a;
    num <<= 8;

    num |= b;
    num <<= 8;

    num |= c;
    num <<= 8;

    num |= d;
    num <<= 8;

    num |= e;
    num <<= 8;

    num |= f;
    num <<= 8;

    num |= g;
    num <<= 8;

    num |= h;

    fprintf(stdout, "%llu\n", num);
}

void printIp() {
    unsigned long long num;
    fscanf(stdin, " %llu", &num);

    int octets[8];
    for (int i = 7; i >= 0; i--) {
        octets[i] = num & 255;
        num >>= 8;
    }

    for (int i = 0; i < 8; i++) {
        fprintf(stdout, "%d", octets[i]);
        if (i != 7) {
            fprintf(stdout, ".");
        }
    }
    fprintf(stdout, "\n");
}

int main(void) {
    int testCnt;

    fscanf(stdin, " %d", &testCnt);
    while (testCnt-- > 0) {
        int type;

        fscanf(stdin, " %d", &type);
        switch (type)
        {
        case IP_TO_NUM:
            printNum();
            break;
        case NUM_TO_IP:
            printIp();
            break;
        }
    }
    return 0;
}
