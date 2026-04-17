#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(sizeof(int) * n);
    int* b = (int*)malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
            if (b[j] < b[j + 1]) {
                int tmp = b[j + 1];
                b[j + 1] = b[j];
                b[j] = tmp;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    printf("%d", sum);
    

    
    return 0;
 }
