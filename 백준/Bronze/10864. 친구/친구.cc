#include <iostream>
#include <cstring>

int    main(void)
{
    int    *friend_cnt;
    int    from, to;
    int    student_cnt, line_cnt;
    
    scanf(" %d %d", &student_cnt, &line_cnt);
    friend_cnt = new int[student_cnt + 1];
    memset(&friend_cnt[1], 0, sizeof(int) * student_cnt);
    while (line_cnt)
    {
        scanf(" %d %d", &from, &to);
        ++friend_cnt[from];
        ++friend_cnt[to];
        --line_cnt;
    }
    for (from = 1; from <= student_cnt; ++from)
        printf("%d\n", friend_cnt[from]);
    return (0);
}