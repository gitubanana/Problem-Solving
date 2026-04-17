#include <iostream>
#include <cstdio>
#include <algorithm>

int max;

int get_sum_price(int *arr, int size, int maximum_price)
{
    int sum;

    sum = 0;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] > maximum_price)
            sum += maximum_price;
        else
            sum += arr[i];
    }
    return (sum);
}

void    parametric_search(int *arr, int size, int available_sum)
{
    int left, right, mid;

    left = 0;
    right = *std::max_element(arr, arr + size);
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (get_sum_price(arr, size, mid) <= available_sum)
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
    int available_sum, requested_sum;

    scanf(" %d", &size);
    arr = new int[size];
    requested_sum = 0;
    for (int i = 0; i < size; ++i)
        scanf(" %d", &arr[i]), requested_sum += arr[i];
    scanf(" %d", &available_sum);

    if (available_sum >= requested_sum)
        max = *std::max_element(arr, arr + size);
    else
        parametric_search(arr, size, available_sum);
    delete[] arr;
    printf("%d\n", max);
    return 0;
}
