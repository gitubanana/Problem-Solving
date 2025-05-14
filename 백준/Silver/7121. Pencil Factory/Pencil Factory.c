#include <stdio.h>
#include <ctype.h>
#define MAX_BUFFER_SIZE 32

char buffer[MAX_BUFFER_SIZE];

int nextInt(void) {
    static int index = -1;
    int ret = 0;

    while (isdigit(buffer[++index])) {
        ret = ret * 10 + (buffer[index] - '0');
    }
    return ret;
}

int countMultiplesOf(long long num, long long end) {
    return end / num;
}

int gcd(int a, int b) {
    while (a && b) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main(void) {
    fread(buffer, sizeof(char), MAX_BUFFER_SIZE, stdin);

    int paintFaultPeriod = nextInt() + 1;
    int varnishFaultPeriod = nextInt() + 1;
    int totalPencil = nextInt();
    int notPainted = countMultiplesOf(paintFaultPeriod, totalPencil);
    int notVarnished = countMultiplesOf(varnishFaultPeriod, totalPencil);
    int neither = countMultiplesOf(lcm(paintFaultPeriod, varnishFaultPeriod), totalPencil);

    printf(
        "%d %d %d %d\n",
        totalPencil - (notPainted + notVarnished - neither),
        neither,
        notVarnished - neither,
        notPainted - neither
    );
    return 0;
}
