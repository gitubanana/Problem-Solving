#include <stdio.h>

const int MINIMUM_BALANCE = -200;

int main(void) {
    while (true) {
        char type;
        int balance, amount;

        fscanf(stdin, " %d %c %d", &balance, &type, &amount);
        if (balance == 0 && type == 'W' && amount == 0) {
            break;
        }

        if (type == 'W') { // withdrawal
            amount = -amount;
        }

        balance += amount;
        if (balance < MINIMUM_BALANCE) {
            printf("Not allowed\n");
        } else {
            printf("%d\n", balance);
        }
    }
    return 0;
}
