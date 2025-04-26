#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
} Array;

void init(Array *this) {
    this->arr = malloc(sizeof(int));
    this->arr[0] = 1;
    this->size = 1;
}

void push(Array *this, int elem) {
    this->arr = realloc(this->arr, sizeof(int) * ++this->size);
    this->arr[this->size - 1] = elem;
}

Array factorsOf(int num) {
    Array arr;

    init(&arr);
    for (int i = 2; i <= num; i++) {
        if (num % i != 0) {
            continue;
        }

        push(&arr, i);
    }
    return arr;
}

int main(void) {
    int p, q;
    scanf(" %d %d", &p, &q);

    Array pFactors = factorsOf(p);
    Array qFactors = factorsOf(q);
    for (int y = 0; y < pFactors.size; y++) {
        for (int x = 0; x < qFactors.size; x++) {
            printf("%d %d\n", pFactors.arr[y], qFactors.arr[x]);
        }
    }

    free(pFactors.arr);
    free(qFactors.arr);
    return 0;
}
