#include <iostream>

int NUMBER_COUNT = 4;

int main() {
    const char *ch = ".*";
    char nums[NUMBER_COUNT + 1];

    scanf(" %s", nums);
    for (int i = 0; i < NUMBER_COUNT; i++) {
        nums[i] -= '0';
    }

    for (int bit = NUMBER_COUNT - 1; bit >= 0; bit--) {
        printf(
            "%c %c   %c %c\n",
            ch[(nums[0] & (1 << bit)) != 0],
            ch[(nums[1] & (1 << bit)) != 0],
            ch[(nums[2] & (1 << bit)) != 0],
            ch[(nums[3] & (1 << bit)) != 0]
        );
    }
    return 0;
}