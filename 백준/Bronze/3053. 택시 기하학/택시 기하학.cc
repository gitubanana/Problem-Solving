#include <stdio.h>
#include <math.h>

int main() {
    int radius;

    scanf(" %d", &radius);
    printf("%.6lf\n", M_PI * radius * radius);
    printf("%.6lf\n", 2.0 * radius * radius);
    return 0;
}