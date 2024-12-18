#include <stdio.h>

int main(void) {
    int medalCnt, kidCnt;
    const char *msg[] = {"No", "Yes"};

    scanf(" %d %d", &medalCnt, &kidCnt);
    printf("%s\n", msg[medalCnt % kidCnt == 0]);
    return (0);
}
