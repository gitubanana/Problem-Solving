#include <stdio.h>
#include <stdlib.h>

void    print_len(int first_len, int *lens, int size)
{
    int    i;
    int    j;
    
    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (first_len >= lens[j])
            {
                first_len++;
                lens[j] = 10001;
            }
            j++;
        }
        i++;
    }
    printf("%d", first_len);
}

int    main(void)
{
    int    i;
    int    cnt;
    int    first_len;
    int    *lens;
    
    i = 0;
    scanf("%d %d", &cnt, &first_len);
    lens = malloc(sizeof(int) * cnt);
    while(i < cnt)
        scanf("%d", &lens[i++]);
    print_len(first_len, lens, cnt);
    free(lens);
}