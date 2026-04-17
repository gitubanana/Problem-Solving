#include <stdio.h>

const int MAX_SIZE = 100;

int size;
int left, right;
int rowSums[MAX_SIZE];
int colSums[MAX_SIZE];
bool exists[MAX_SIZE * MAX_SIZE + 1];

bool isMagicSquare(void) {
    int validValue = size * (size * size + 1) / 2;

    if (left != validValue || right != validValue) {
        return false;
    }

    for (int i = 0; i < size; i++) {
        if (rowSums[i] != validValue || colSums[i] != validValue) {
            return false;
        }
    }
    return true;
}

int main(void) {
    scanf(" %d", &size);
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int num;

            scanf(" %d", &num);
            if (exists[num]) {
                printf("FALSE");
                return 0;
            }
            exists[num] = true;
            rowSums[y] += num;
            colSums[x] += num;
            left += (y == x) * num;
            right += (y == size - x - 1) * num;
        }
    }

    printf("%s\n", isMagicSquare() ? "TRUE" : "FALSE");
    return 0;
}
