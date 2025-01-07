#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int fileCnt;
    int *files;

    scanf(" %d", &fileCnt);
    files = malloc(sizeof(int) * fileCnt);
    for (int i = 0; i < fileCnt; i++) {
        scanf(" %d", &files[i]);
    }

    long long clusterSize;
    long long usedDiskSize = 0;

    scanf(" %d", &clusterSize);
    for (int i = 0; i < fileCnt; i++) {
        if (files[i] == 0) {
            continue;
        }

        long long clusterCnt = files[i] / clusterSize;
        if (clusterCnt * clusterSize != files[i]) {
            ++clusterCnt;
        }

        usedDiskSize += clusterCnt * clusterSize;
    }

    printf("%lld\n", usedDiskSize);
    free(files);
    return 0;
}
