#include <iostream>

bool    all_different(int *arr, int size)
{
    int i, j;
    
    for (i = 0; i < size - 1; ++i)
        for (j = i + 1; j < size; ++j)
            if (arr[i] == arr[j])
                return (false);
    return (true);
}

void    print_min_m(int *arr, int size)
{
    int i, divisor;
    int *remain = new int[size];

    divisor = 1;
    while (1)
    {
        for (i = 0; i < size; ++i)
            remain[i] = arr[i] % divisor;
        if (all_different(remain, size))
            break ;
        divisor++;
    }
    printf("%d\n", divisor);
    delete[] remain;
}

int main(void)
{
    int test_cnt;
    int *arr, size, i;
    
    scanf(" %d", &test_cnt);
    while (test_cnt--)
    {
        scanf(" %d", &size);
        arr = new int[size];
        for (i = 0; i < size; ++i)
            scanf(" %d", &arr[i]);
        print_min_m(arr, size);
        delete[] arr;
    }
    return (0);
}