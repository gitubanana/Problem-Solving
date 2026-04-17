#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>

const int   FIXED = 0;

void    print_leaks(int *leaks, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << (leaks[i] == FIXED ? 0 : leaks[i]) << " ";
    std::cout << std::endl;
}

void    print_tape_cnt(int *leaks, int leaks_cnt, int tape_len)
{
    int i, leak_idx;
    int tape_cnt = 0;

    while (1)
    {
        for (leak_idx = 0; leak_idx < leaks_cnt; leak_idx++)
            if (leaks[leak_idx] != FIXED)
                break ;
        if (leak_idx == leaks_cnt)
            break ;
        for (i = leak_idx + 1; i < leaks_cnt; i++)
        {
            if (leaks[i] - leaks[leak_idx] + 1 <= tape_len)
                leaks[i] = FIXED;
        }
        leaks[leak_idx] = FIXED;
        tape_cnt++;
    }
    printf("%d", tape_cnt);
}

int main(void)
{
    int *leaks;
    int i, leaks_cnt, tape_len;

    std::cin >> leaks_cnt >> tape_len;
    leaks = new int[leaks_cnt];
    for (i = 0; i < leaks_cnt; i++)
        std::cin >> leaks[i];
    std::sort(leaks, leaks + leaks_cnt);
    print_tape_cnt(leaks, leaks_cnt, tape_len);
    delete[] leaks;
    return (0);
}
