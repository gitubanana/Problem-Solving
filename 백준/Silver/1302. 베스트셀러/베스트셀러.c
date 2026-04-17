#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    str[1000][51];

void    print_ans(int size)
{
    int    i, j;
    int    max, cnt;
    char    *ans;
    char    *tmp;
    
    max = 0;
    for (i = 0; i < size; i++)
    {
        cnt = 0;
        tmp = str[i];
        for (j = 0; j < size; j++)
            if (strcmp(tmp, str[j]) == 0)
                cnt++;
        if (max < cnt)
        {
            max = cnt;
            ans = tmp;
        }
    }
    printf("%s", ans);
}

int    cmp(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

int    main(void)
{
    int    i, n;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%s", str[i]);
    qsort(str, n, 51, cmp);
    print_ans(n);
}