#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long a,b;
    scanf("%lld %lld", &a, &b);
    printf("%lld", llabs(a - b));
}