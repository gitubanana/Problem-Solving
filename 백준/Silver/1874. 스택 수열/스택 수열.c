#include <stdio.h>

int    stack[100001];
int    top = -1;
int    arr[100001];

void    push(int data, int flag)
{
    if (flag)
        printf("+\n");
    stack[++top] = data;
}

int    pop(int flag)
{
    if (flag)
        printf("-\n");
    return stack[top--];
}

int    peek()
{
    return stack[top];
}

int    bool_or_ans(int size, int flag)
{
    int    i, j;
    
    j = 1;
    push(j++, flag);
    for (i = 0; i < size; i++)
    {
        if (peek() < arr[i])
        {
            while (j <= arr[i])
                push(j++, flag);
            pop(flag);
        }
        else if (peek() == arr[i])
            pop(flag);
        else
            return (0);
    }
    return (1);
}

int    main(void)
{
    int    i, n;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    if (bool_or_ans(n, 0))
        bool_or_ans(n, 1);
    else
        printf("NO");
}