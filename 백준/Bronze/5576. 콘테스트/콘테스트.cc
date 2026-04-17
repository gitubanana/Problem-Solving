#include <iostream>
#include <algorithm>

const int    MAX = 10;

int    main(void)
{
    int    w_score[MAX];
    int    k_score[MAX], i;
    
    for (i = 0; i < MAX; ++i)
        scanf(" %d", &w_score[i]);
    for (i = 0; i < MAX; ++i)
        scanf(" %d", &k_score[i]);
    std::sort(w_score, w_score + MAX);
    std::sort(k_score, k_score + MAX);
    printf("%d %d\n", w_score[MAX - 1] + w_score[MAX - 2] + w_score[MAX - 3],
                       k_score[MAX - 1] + k_score[MAX - 2] + k_score[MAX - 3]);
    return (0);
}