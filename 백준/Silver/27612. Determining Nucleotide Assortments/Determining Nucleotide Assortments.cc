#include <stdio.h>
#include <stdlib.h>

class Elem {
public:
    char ch;
    int cnt;

    inline bool operator<(const Elem &other) const {
        return this->cnt < other.cnt;
    }
};

const int MAX_SIZE = 5e4 + 1;
const char NUCLEOTIDE[] = "ATGC";
const int NUCLEOTIDE_COUNT = sizeof(NUCLEOTIDE) - 1;

char dna[MAX_SIZE + 1];
int cnt[MAX_SIZE][NUCLEOTIDE_COUNT];

int indexOf(char ch) {
    for (int i = 0; NUCLEOTIDE[i]; i++) {
        if (NUCLEOTIDE[i] == ch) {
            return i;
        }
    }

    exit(1);
    return -1;
}

void prefixSum(void) {
    for (int i = 1; dna[i]; i++) {
        for (int c = 0; c < NUCLEOTIDE_COUNT; c++) {
            cnt[i][c] = cnt[i - 1][c];
        }
        cnt[i][indexOf(dna[i])]++;
    }
}

void insertionSort(Elem arr[NUCLEOTIDE_COUNT]) {
    for (int i = 1; i < NUCLEOTIDE_COUNT; i++) {
        Elem cmp = arr[i];
        int j = i - 1;

        for (; j >= 0 && cmp.cnt > arr[j].cnt; j--) {
            arr[j+1] = arr[j];
        }

        arr[j+1] = cmp;
    }
}

void printSortedNucloetide(int start, int end) {
    static Elem arr[NUCLEOTIDE_COUNT];

    for (int i = 0; i < NUCLEOTIDE_COUNT; i++) {
        arr[i].ch = NUCLEOTIDE[i];
        arr[i].cnt = cnt[end][i] - cnt[start - 1][i];
    }

    insertionSort(arr);

    for (int i = 0; i < NUCLEOTIDE_COUNT; i++) {
        fprintf(stdout, "%c", arr[i].ch);
    }
    fprintf(stdout, "\n");
}

int main(void) {
    int qCnt;

    fscanf(stdin, " %s %d", &dna[1], &qCnt);
    prefixSum();
    for (int q = 0; q < qCnt; q++) {
        int start, end;

        fscanf(stdin, " %d %d", &start, &end);
        printSortedNucloetide(start, end);
    }
    return 0;
}
