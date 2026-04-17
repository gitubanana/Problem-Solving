#include <iostream>
#include <algorithm>

struct t_organism
{
    int *arr;
    int size;


    t_organism(int size)
        : size(size), arr(new int[size])
    {
    }

    ~t_organism(void)
    {
        delete[] arr;
    }

    inline int *begin(void)
    {
        return (arr);
    }

    inline int *end(void)
    {
        return (arr + size);
    }
};

void    print_edible(t_organism &a, t_organism &b)
{
    int i;
    int edible_cnt = 0;

    std::sort(b.begin(), b.end());
    for (i = 0; i < a.size; ++i)
    {
        edible_cnt += std::lower_bound(b.begin(), b.end(), a.arr[i]) - b.begin();
    }
    printf("%d\n", edible_cnt);
}

int main(void)
{
    int i;
    int test_cnt;
    int a_size, b_size;

    scanf(" %d", &test_cnt);
    while (test_cnt)
    {
        scanf(" %d %d", &a_size, &b_size);
        t_organism  a(a_size), b(b_size);

        for (i = 0; i < a_size; ++i)
            scanf(" %d", &a.arr[i]);

        for (i = 0; i < b_size; ++i)
            scanf(" %d", &b.arr[i]);

        print_edible(a, b);

        --test_cnt;
    }
    return (0);
}