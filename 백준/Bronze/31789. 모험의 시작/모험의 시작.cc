#include <stdio.h>
#define MAX(a, b) (a) > (b) ? (a) : (b)

int main(void) {
    int weaponCnt;
    int asset, opponent;
    int maxDamage = 0;

    scanf(" %d %d %d", &weaponCnt, &asset, &opponent);
    for (int w = 0; w < weaponCnt; w++) {
        int cost, damage;

        scanf(" %d %d", &cost, &damage);
        if (cost <= asset) {
            maxDamage = MAX(maxDamage, damage);
        }
    }

    const char *msg[] = {"NO", "YES"};
    printf("%s\n", msg[maxDamage > opponent]);
    return 0;
}
