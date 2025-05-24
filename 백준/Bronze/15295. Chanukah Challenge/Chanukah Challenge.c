#include <stdio.h>
#define CHANUKAH_CANDLE(day) \
    ((day) + 1) * day / 2 + day

int main(void) {
    int testCnt;

    fscanf(stdin, " %d", &testCnt);
    for (int t = 1; t <= testCnt; t++) {
        int dataSetId, day;

        fscanf(stdin, " %d %d", &dataSetId, &day);
        fprintf(stdout, "%d %d\n", dataSetId, CHANUKAH_CANDLE(day));
    }
    return 0;
}
