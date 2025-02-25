#include <stdio.h>

int main(void) {
    int taskCnt, endTime;
    int doneCnt = 0, curTime = 0;

    fscanf(stdin, " %d %d", &taskCnt, &endTime);
    for (; doneCnt < taskCnt; doneCnt++) {
        int burstTime;

        fscanf(stdin, " %d", &burstTime);
        curTime += burstTime;
        if (curTime > endTime) {
            break;
        }
    }

    fprintf(stdout, "%d\n", doneCnt);
    return 0;
}
