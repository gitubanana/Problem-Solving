#include <iostream>
#include <algorithm>

unsigned int max;

int count_lan(int *arr, int size, int divisor)
{
    int i;
    int cnt;

    cnt = 0;
    for (i = 0; i < size; ++i)
        cnt += arr[i] / divisor;
    return (cnt);
}

void    parametric_search(int *arr, int size, int make_cnt)
{
    unsigned int left, right, mid;

    left = 1;
    right = arr[size - 1];
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (count_lan(arr, size, mid) >= make_cnt)
        {
            max = std::max(max, mid);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
}

int main()
{
    int *arr, size;
    int make_cnt;
    
    scanf(" %d %d", &size, &make_cnt);
    arr = new int[size];
    for (int i = 0; i < size; ++i)
        scanf(" %d", &arr[i]);
    std::sort(arr, arr + size);
    parametric_search(arr, size, make_cnt);
    printf("%u\n", max);
    delete[] arr;
    return 0;
}
