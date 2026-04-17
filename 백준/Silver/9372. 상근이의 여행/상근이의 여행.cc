#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>

int main()
{
    int test_cnt;
    int v_cnt, e_cnt;
    int a, b;

    scanf(" %d", &test_cnt);
    while (test_cnt)
    {
        scanf(" %d %d", &v_cnt, &e_cnt);
        while (e_cnt)
        {
            scanf(" %d %d", &a, &b);
            --e_cnt;
        }
        printf("%d\n", v_cnt - 1);
        --test_cnt;
    }
    return 0;
}
