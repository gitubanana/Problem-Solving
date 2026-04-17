#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define SWAP(a, b) { int c = *a; *a = *b; *b = c; }
#define MAX 50

int		size, max;
char	str[MAX][MAX + 1];

int	get_max_candy(void)
{
	int	i, j;
	int	max, cnt;

	max = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0, cnt = 1; j < size - 1; j++)
		{
			if (str[i][j] != str[i][j + 1])
			{
				if (max < cnt)
					max = cnt;
				cnt = 1;
			}
			else
				cnt++;
		}
		if (max < cnt)
			max = cnt;
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0, cnt = 1; j < size - 1; j++)
		{
			if (str[j][i] != str[j + 1][i])
			{
				if (max < cnt)
					max = cnt;
				cnt = 1;
			}
			else
				cnt++;
		}
		if (max < cnt)
			max = cnt;
	}
	return (max);
}

void	print_max(void)
{
	int	i, j;
	int	eatable_cnt;

	max = get_max_candy();
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			SWAP(&str[i][j], &str[i][j + 1]);
			eatable_cnt = get_max_candy();
			if (max < eatable_cnt)
				max = eatable_cnt;
			SWAP(&str[i][j], &str[i][j + 1]);
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			SWAP(&str[j][i], &str[j + 1][i]);
			eatable_cnt = get_max_candy();
			if (max < eatable_cnt)
				max = eatable_cnt;
			SWAP(&str[j][i], &str[j + 1][i]);
		}
	}
	printf("%d", max);
}

int	main(void)
{
	int		i;

	scanf("%d", &size);
	for (i = 0; i < size; i++)
		scanf("%s", str[i]);
	print_max();
	return (0);
}
