#include <stdio.h>

int main() {
    int cost;
    int supplementary;
    int budget = (1 << 10) - 1;
    const char *msg = "Impossible";

    scanf(" %d %d", &cost, &supplementary);
    cost -= budget;
    if (cost <= 0) {
        msg = "No thanks";
    } else if ((cost & supplementary) == cost) {
        msg = "Thanks";
    }

    printf("%s\n", msg);
    return 0;
}