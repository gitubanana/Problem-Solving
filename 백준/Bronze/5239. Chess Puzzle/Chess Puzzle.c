#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int testCount;

    scanf(" %d", &testCount);
    while (testCount-- > 0) {
        int rookCount;
        int yOccupied = 0;
        int xOccupied = 0;
        bool isNotSafe = false;

        scanf(" %d", &rookCount);
        while (rookCount-- > 0) {
            int y, x;

            scanf(" %d %d", &y, &x);
            if (isNotSafe) {
                continue;
            }

            if (yOccupied & (1 << y)) {
                isNotSafe = true;
            } else {
                yOccupied |= (1 << y);
            }

            if (xOccupied & (1 << x)) {
                isNotSafe = true;
            } else {
                xOccupied |= (1 << x);
            }
        }

        printf("%sSAFE\n", isNotSafe ? "NOT " : "");
    }

    return 0;
}
