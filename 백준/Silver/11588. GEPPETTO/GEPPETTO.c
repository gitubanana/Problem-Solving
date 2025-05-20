#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_BUFFER_SIZE 2416
#define MAX_INGREDIENTS 21

int menuCnt;
int ingredientCnt;
int badPairOf[MAX_INGREDIENTS];
char buffer[MAX_BUFFER_SIZE];

int nextInt(void) {
    static int index = -1;
    int ret = 0;

    while (isdigit(buffer[++index])) {
        ret = ret * 10 + (buffer[index] - '0');
    }
    return ret;
}

bool isBadIngredient(int ingredient, int denyList) {
    return denyList & (1 << ingredient);
}

void backTracking(int ingredient, int denyList) {
    if (ingredient == ingredientCnt + 1) {
        menuCnt++;
        return;
    }

    const int nextIngredient = ingredient + 1;

    backTracking(nextIngredient, denyList);
    if (!isBadIngredient(ingredient, denyList)) {
        backTracking(nextIngredient, denyList | badPairOf[ingredient]);
    }
}

int main(void) {
    fread(buffer, sizeof(char), MAX_BUFFER_SIZE, stdin);

    ingredientCnt = nextInt();
    int badPairCnt = nextInt();
    for (int i = 0; i < badPairCnt; i++) {
        int a = nextInt();
        int b = nextInt();

        badPairOf[a] |= (1 << b);
        badPairOf[b] |= (1 << a);
    }

    backTracking(1, 0);
    printf("%d\n", menuCnt);
    return 0;
}
