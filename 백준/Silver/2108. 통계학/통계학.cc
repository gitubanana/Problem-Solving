#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

const int   MAX = 8001;
const int   OFFSET = 4000;

int cnt[MAX];

int most_frequent_num(void)
{
    int num;
    int prev_num;
    int came_here;
    int cur_freq, prev_freq;

    prev_num = INT_MIN;
    cur_freq = came_here = 0;
    for (int i = 0; i < MAX; ++i)
    {
        if (cnt[i] > cur_freq)
        {
            came_here = 0;
            cur_freq = cnt[i], num = i;
        }
        else if (!came_here && cnt[i] == cur_freq)
        {
            came_here = 1;
            prev_freq = cur_freq, prev_num = i;
        }
    }
    if (prev_freq == cur_freq)
        num = prev_num;
    return (num - OFFSET);
}

int main()
{
    int i;
    int sum;
    int *arr, size;

    scanf(" %d", &size);
    sum = 0;
    arr = new int[size];
    for (i = 0; i < size; ++i)
    {
        scanf(" %d", &arr[i]);
        sum += arr[i];
        ++cnt[arr[i] + OFFSET];
    }
    std::sort(arr, arr + size);

    double  avg = round(static_cast<double>(sum) / size);
    if (avg == -0)
        avg = 0;
    printf("%.0lf\n", avg);
    printf("%d\n", arr[size / 2]);
    printf("%d\n", most_frequent_num());
    printf("%d\n", arr[size - 1] - arr[0]);
    return 0;
}
