#include <stdio.h>

const int WEIGHTS[] = {2, 7, 6, 5, 4, 3, 2};
const int SIZE = sizeof(WEIGHTS) / sizeof(WEIGHTS[0]);
const char CHECK[] = "JABCDEFGHIZ";
const int MODULO = sizeof(CHECK) - 1;

int main() {
    char nice[SIZE+1];
    int sum = 0;

    scanf(" %s", nice);
    for (int i = 0; i < SIZE; i++) {
        sum += (nice[i] - '0') * WEIGHTS[i];
    }

    printf("%c", CHECK[sum % MODULO]);
    return 0;
}
