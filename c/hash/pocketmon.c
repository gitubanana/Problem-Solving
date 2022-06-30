#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int	num;
	char	str[21];
}name;

int	cmp_str(const void *a, const void *b);
void	bin_search(char *tmp, int left, int right);

char	tmp[21];
char	src[100000][21];
name	sorted[100000];

int	main(void)
{
	int	i;
	int	n, quiz;

	scanf("%d %d", &n, &quiz);

	for (i = 0; i < n; i++)
	{
		scanf("%s", src[i]);
		strcpy(sorted[i].str, src[i]);
		sorted[i].num = i + 1;
	}
	qsort(sorted, n, sizeof(name), cmp_str);
	for (i = 0; i < quiz; i++)
	{
		scanf("%s", tmp);
		if (tmp[0] >= '0' && tmp <= '9')
			printf("%s\n", src[atoi(tmp) - 1]);
		else
			printf("%d\n", bin_search(tmp, 0, n - 1));
	}
	return (0);
}

int	cmp_str(const void *a, const void *b)
{
	return strcmp(((name *)a)->str, ((name *)b)->str);
}

void	bin_search(char *tmp, int left, int right)
{
	int	mid, result;

	while (left <= right)
	{
		mid = (left + right) / 2;
		result = strcmp(sorted[mid].str, aim);

		if (result == 0)
			return sorted[mid].num;
		else if (result > 0)
			right = mid - 1;
		else
			left = mid + 1;
	}
}

