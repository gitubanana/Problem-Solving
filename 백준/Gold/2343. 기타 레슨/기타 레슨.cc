#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>

int min = INT_MAX;
int sum;

int count_blueRay(int *arr, int size, int blueRay_size)
{
    int cnt;
    int cur_size, next_size;

    cnt = 1;
    cur_size = 0;
    for (int i = 0; i < size; ++i)
    {
        next_size = cur_size + arr[i];
        if (next_size <= blueRay_size)
            cur_size = next_size;
        else
        {
            cur_size = arr[i];
            ++cnt;
        }
    }
    return (cnt);
}

void    parametric_search(int *arr, int size, int make_cnt)
{
    int left, right, mid;

    left = *std::max_element(arr, arr + size);
    right = sum;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (count_blueRay(arr, size, mid) <= make_cnt)
        {
            min = std::min(min, mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
}

int main()
{
    int make_cnt;
    int *arr, size;

    scanf(" %d %d", &size, &make_cnt);
    arr = new int[size];
    for (int i = 0; i < size; ++i)
        scanf(" %d", arr + i), sum += arr[i];
    parametric_search(arr, size, make_cnt);
    printf("%d\n", min);
    delete[] arr;
    return 0;
}
