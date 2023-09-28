#include <iostream>
#include <climits>
#include <map>

const int   MAX = 100000;

int     min = INT_MAX;
char    mbti_arr[MAX][5];
std::map<std::string, int>  _map;

int get_mental_distance(char *a, char *b)
{
    int distance = 0;

    for (int i = 0; a[i]; ++i)
    {
        if (a[i] != b[i])
            ++distance;
    }
    return (distance);
}

inline int get_three_distance(char *a, char *b, char *c)
{
    return (get_mental_distance(a, b)
            + get_mental_distance(b, c)
            + get_mental_distance(a, c));
}

void    find_min_distance(int arr_size)
{
    for (int i = 0; i < arr_size - 2; ++i)
    {
        for (int j = i + 1; j < arr_size - 1; ++j)
        {
            for (int k = j + 1; k < arr_size; ++k)
            {
                min = std::min(min,
                    get_three_distance(mbti_arr[i], mbti_arr[j], mbti_arr[k]));
            }
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int test_cnt;
    int arr_size;

    std::cin >> test_cnt;
    while (test_cnt)
    {
        std::cin >> arr_size;
        for (int i = 0; i < arr_size; ++i)
            std::cin >> mbti_arr[i];

        if (arr_size > 32)
            min = 0;
        else
            find_min_distance(arr_size);

        std::cout << min << '\n';
        min = INT_MAX;
        --test_cnt;
    }

    return (0);
}
