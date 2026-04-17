#include <stdio.h>
#include <string.h>

const int MAX_SIZE = 256;

int main(void) {
    char ans[MAX_SIZE + 1];
    char cmp[MAX_SIZE + 1];
    int coldestTemp = 201;
    int cmpTemp;

    do {
        fscanf(stdin, " %s %d", cmp, &cmpTemp);
        if (coldestTemp > cmpTemp) {
            coldestTemp = cmpTemp;
            strcpy(ans, cmp);
        }
    } while (strcmp(cmp, "Waterloo") != 0);

    fprintf(stdout, "%s\n", ans);
    return 0;
}
