#include <stdio.h>
#include <stdlib.h>
#define swap(a, b){int c = a; a = b; b = c;}

void    quick_sort(int *arr, int left, int right)
{
    int    l;
    int    r;
    int    pivot;
    
    l = left;
    r = right;
    pivot = arr[(left + right) / 2];
    do
    {
        while (arr[l] > pivot)
            l++;
        while (arr[r] < pivot)
            r--;
        if (l <= r)
        {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }while (l <= r);
    if (left < r)
        quick_sort(arr, left, r);
    if (l < right)
        quick_sort(arr, l, right);
}

void    print_min(int *arr, int size)
{
    int    i;
    int    sum;
    
    i = 0;
    sum = 0;
    while (i < size / 3 * 3)
    {
        sum += arr[i] + arr[i + 1];
        i += 3;
    }
    while (i < size)
    {
        sum += arr[i];
        i++;
    }
    printf("%d", sum);
}

int    main(void)
{
    int    i;
    int    n;
    int    *price;
    
    i = 0;
    scanf("%d", &n);
    price = malloc(sizeof(int) * n);
    while (i < n)
        scanf("%d", &price[i++]);
    quick_sort(price, 0, n - 1);
    print_min(price, n);
    free(price);
}