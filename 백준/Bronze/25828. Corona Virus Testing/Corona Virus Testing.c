#include <stdio.h>

int getAns(int individual, int group) {
    if (individual < group) {
        return 1;
    }

    if (individual > group) {
        return 2;
    }

    return 0;
}

int main(void) {
    int groupCount;
    int peopleInGroup;
    int positiveGroupCount;

    scanf(" %d %d %d", &groupCount, &peopleInGroup, &positiveGroupCount);

    int individual = groupCount * peopleInGroup;
    int group = groupCount + positiveGroupCount * peopleInGroup;

    printf("%d\n", getAns(individual, group));
    return 0;
}
