#include <stdio.h>

int main(void)
{
    int n=0;
    scanf("%d", &n);
    if (n == 4 || n == 7) {
        printf("%d\n", -1);
    }
    else {
        printf("%d\n", n/5 + (n-(n/5)*5)/3 + (n-(n/5)*5)%3);
    }
    return 0;
}