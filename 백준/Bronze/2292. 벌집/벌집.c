#include <stdio.h>
#include <math.h>

int calculate (int x)
{
    return (int) (ceil ( 0.5 + pow (0.25 + (double)(x - 1) / 3, 0.5) ));
}

int main (void)
{
    int n, dimension;
    scanf ("%d", &n);
    
    dimension = calculate (n);
    printf ("%d\n", dimension);
    
    return 0;
}