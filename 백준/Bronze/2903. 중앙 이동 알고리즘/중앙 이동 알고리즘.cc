#include <iostream>
#include <cmath>

int main(void)
{
    int n;
    int ans;
    int length;

    scanf(" %d", &n);
    ans = 4;
    length = 2;
    for (int i = 1; i <= n; ++i)
    {
        length = length * 2 - 1;
        ans = pow(length, 2);
    }
    printf("%d\n", ans);
    return (0);
}
