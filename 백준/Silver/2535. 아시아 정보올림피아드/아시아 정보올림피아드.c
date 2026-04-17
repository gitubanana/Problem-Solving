#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int    c; //country
    int    n; //number
    int    s; //score
}part; //participant

void    swap(part *a, part *b)
{
    part tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    quick_sort(part *arr, int left, int right)
{
    int    l;
    int    r;
    int    pivot;
    
    l = left;
    r = right;
    pivot = arr[(left + right) / 2].s;
    do
    {
        while (arr[l].s > pivot)
            l++;
        while (arr[r].s < pivot)
            r--;
        if (l <= r)
        {
            swap(&arr[r], &arr[l]);
            l++;
            r--;
        }
    }while (l <= r);
    if (left < r)
        quick_sort(arr, left, r);
    if (l < right)
        quick_sort(arr, l, right);
}

void    print_part(part n)
{
    printf("%d %d\n", n.c, n.n);
}

void    print_medal(part *arr, int size)
{
    int    i;
    
    i = 2;
    quick_sort(arr, 0, size - 1);
    print_part(arr[0]);
    print_part(arr[1]);
    if (arr[0].c != arr[1].c)
        print_part(arr[2]);
    else
    {
        while (i < size)
        {
            if (arr[i].c != arr[0].c)
            {
                print_part(arr[i]);
                break;
            }
            i++;
        }
    }
}

int    main(void)
{
    int    i;
    int    n;
    part    *arr;
    
    i = 0;
    scanf("%d", &n);
    arr = malloc(sizeof(part) * n);
    while (i < n)
    {
        scanf("%d %d %d", &arr[i].c, &arr[i].n, &arr[i].s);
        i++;
    }
    print_medal(arr, n);
    free(arr);
}