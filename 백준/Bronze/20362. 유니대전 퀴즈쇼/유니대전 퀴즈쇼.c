#include <stdio.h>

typedef struct
{
    char    name[11];
    char    ans[11];
}ans;

int    is_the_same(char *a, char *b)
{
    int    i;
    
    i = 0;
    while (a[i])
    {
        if (a[i] != b[i])
            return (0);
        i++;
    }
    if (a[i] == '\0' && b[i] == '\0') 
        return (1);
    return (0);
}

void    print_ans(ans *strs, int a)
{
    int    i;
    int    cnt;
    
    cnt = 0;
    for (i = 0; i < a; i++)
        if (is_the_same(strs[i].ans, strs[a].ans))
            cnt++;
    printf("%d\n", cnt);
}

int    main(void)
{
    int    i, n, tmp;
    char    nick[11];
    ans    strs[1000];
    
    scanf("%d %s", &n, nick);
    for (i = 0; i < n; i++)
    {
        scanf("%s %s", strs[i].name, strs[i].ans);
        if (is_the_same(strs[i].name, nick))
            tmp = i;
    }
    print_ans(strs, tmp);
}